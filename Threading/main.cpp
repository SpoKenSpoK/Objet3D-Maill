/* Projet de Système: "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016   *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL              *
*               - Programmation avec thread -                */

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <cstdlib>
#include "../Sequentiel/mesh.hpp"
#include "../Sequentiel/face.hpp"
#include "../Sequentiel/point.hpp"

/*
    Nous avons besoin de passer plusieurs paramètres dans notre thread.
    Pour ce faire l'utilisation d'une structure nous semble approprié.
*/
struct ThreadParams{
    unsigned int _max;
    unsigned int _min;
    Face* _tab_face;
    Point* _tab_point;
    Mesh* _mesh;
};

void* calcul(void* args)
{
    ThreadParams *thread_params = (ThreadParams*)args;  // Nous castons le void* obtenu en paramètre en un pointeur sur notre structure
    /*
        Cette boucle for reprend le même principe que le séquentiel, à la chose prêt que l'addition des aires
        se fait dans une boucle à part pour éviter le partage de données dans les threads.
        Il est évident que voulant "threader" à la main il nous est nécessaire de faire varier les intervalles dans lesquels vont itérer nos boucles for.
        D'où la précense de thread_params->_min et ->_max .
    */
    for(unsigned int i=thread_params->_min; i<thread_params->_max; ++i){
        thread_params->_tab_face[i].setSeg_one( thread_params->_tab_point->calc_length( thread_params->_tab_face[i].getS_one(), thread_params->_tab_face[i].getS_two() ) );
        thread_params->_tab_face[i].setSeg_two( thread_params->_tab_point->calc_length( thread_params->_tab_face[i].getS_two(), thread_params->_tab_face[i].getS_three() ) );
        thread_params->_tab_face[i].setSeg_three( thread_params->_tab_point->calc_length( thread_params->_tab_face[i].getS_three(), thread_params->_tab_face[i].getS_one() ) );
    }

    pthread_exit(NULL);
}

int main()
{
    const unsigned short THREAD_COUNT = 8;

    Face* tab_face;
    Point* tab_point;

    std::string name_fichier;
    bool is_here = false;

    do{
        std::cout << "Entrez le nom du fichier .off a tester: " << std::endl;
        std::cin >> name_fichier;
        name_fichier+=".off";

        std::ifstream fichier(name_fichier.c_str(), std::ios::in);
        if(fichier)
        {
            is_here = true;
            fichier.seekg(4, fichier.beg);
            unsigned int point_count;
            unsigned int face_count;
            fichier >> point_count >> face_count;
            Mesh mesh(point_count, face_count);
            tab_point = new Point[mesh.getNumberof_p()];
            tab_face = new Face[mesh.getNumberof_f()];
            fichier.seekg(3, fichier.cur);

            double p_value;
            for(unsigned int i=0; i<mesh.getNumberof_p(); ++i){
                fichier >> p_value;
                tab_point[i].setP_one(p_value);

                fichier >> p_value;
                tab_point[i].setP_two(p_value);

                fichier >> p_value;
                tab_point[i].setP_three(p_value);
            }

            unsigned int s_value;
            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                fichier >> s_value;
                fichier >> s_value;
                tab_face[i].setS_one(s_value);

                fichier >> s_value;
                tab_face[i].setS_two(s_value);

                fichier >> s_value;
                tab_face[i].setS_three(s_value);
            }

            fichier.close();

            int segments = (face_count - (face_count%THREAD_COUNT))/THREAD_COUNT;   // Représente la taille des segments dans lesquels vont boucler chacun de nos threads.
            pthread_t* threads_array = new pthread_t[THREAD_COUNT];                 // Création d'un tableau dynamique de pointeur
            ThreadParams* thread_params = new ThreadParams[THREAD_COUNT];           // Création d'un tableau dynamique sur la structure précédemment définie
			for(unsigned int i=0; i<THREAD_COUNT; ++i){                             // Cette boucle for remplie chacun des paramètres des threads dont nous allons avoir besoin
                thread_params[i]._max=(i+1)*segments;
                thread_params[i]._min=i*segments;
                thread_params[i]._tab_face=tab_face;
                thread_params[i]._tab_point=tab_point;
                thread_params[i]._mesh=&mesh;
                pthread_create(&threads_array[i], NULL, calcul, &thread_params[i]); // Création d'un thread 'i' ayant des paramètres 'i', ce dernier est alors executé
            }

            for(unsigned int i=0; i<THREAD_COUNT; ++i){ pthread_join(threads_array[i],NULL); }  // Boucle for permettant la jointure de tous les threads

            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){                                 // Calcul de l'aire ici non threadé pour éviter tout conflit de variable partagée
                mesh.setFull(mesh.getFull()+tab_face[i].calc_area());

                if(i==mesh.getNumberof_f()-1)
                    system("../Sequentiel/./grepmod");
            }

            delete [] threads_array;    // Suppression du tableau de threads
            delete [] thread_params;    // Suppression du tableau de paramètres du thread

            std::cout << "\nNombre de sommets : "       << mesh.getNumberof_p() << std::endl;
            std::cout << "Nombre de faces : "           << mesh.getNumberof_f() << std::endl;
            std::cout << "Aire totale de la forme : "   << mesh.getFull() << std::endl;
        }
        else
            std::cerr << "Impossible d'ouvrir le fichier : " << name_fichier << " !" << std::endl;

    }while(!is_here);

    delete [] tab_face;
    delete [] tab_point;

    return 0;
}
