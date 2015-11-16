/* Projet de Système: "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016   *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL              *
*               - Programmation séquentielle -                */

#include <iostream>
#include <fstream>
#include <time.h>
#include "mesh.hpp"
#include "face.hpp"
#include "point.hpp"
#include <omp.h>

int main()
{
    // Création d'un tableau de Faces & de Points
    Face* tab_face;
    Point* tab_point;

    // Création des deux clock nous permettant de calculer le temps d'exécution du programme
    double clock_debut;
    double clock_fin;

    // Clock pour le temps d'éxecution de la lecture
    double clock_debut_lecture;
    double clock_fin_lecture;

    std::string name_fichier; //< Chaîne de caractère créer ici évitant ainsi de la recréer au cas où la saisie dans la boucle do -> while serait fausse (fichier inexistant)
    bool is_here = false;   //< Booléen permettant d'éxecuter la boucle while ci-dessous : prend true si le fichier est vérifié

    do{
        std::cout << "Entrez le nom du fichier .off a tester: " << std::endl;
        std::cin >> name_fichier;

        // Ouverture du fichier en lecture
        std::ifstream fichier(name_fichier.c_str(), std::ios::in);
        if(fichier) // Test pour savoir si le fichier est bien présent
        {
            is_here = true; //< Si le fichier est vérifié alors la valeur et vraie, ainsi on peut sortir de la boucle do -> while

            clock_debut_lecture = (double)clock()/CLOCKS_PER_SEC;

            // On se place au quatrième octet dans le fichier (en partant du début), ici après le "OFF"
            fichier.seekg(4, fichier.beg);

            unsigned int point_count = 0;   //< Création d'un entier positif représentant le nombre de point présent dans le fichier
            unsigned int face_count = 0;    //< Création d'un autre entier positif, celui représentant le nombre de face

            // Lecture du fichier, les deux premiers entiers positifs sont insérés dans les variables précédemments définies
            fichier >> point_count >> face_count;

            // Création d'une instance de Mesh en insérant dans le constructeur le nombre de point et face obtenu
            Mesh mesh(point_count, face_count);
            mesh.setFull(0.0);

            tab_point = new Point[mesh.getNumberof_p()];    //< Allocation dynamique du tableau de Point prennant comme taille le nombre de point
            tab_face = new Face[mesh.getNumberof_f()];  //< Allocation dynamique du tableau de Face prennant comme taille le nombre de face

            // On vient se placer à la ligne évitant le '0' (en partant de la dernière position du curseur)
            fichier.seekg(3, fichier.cur);

            // Lecture des coordonnées de chaque sommet
            long double p_value;
            for(unsigned int i=0; i<mesh.getNumberof_p(); ++i){
                fichier >> p_value;
                tab_point[i].setP_one(p_value);

                fichier >> p_value;
                tab_point[i].setP_two(p_value);

                fichier >> p_value;
                tab_point[i].setP_three(p_value);
            }

            // Lecture des emplacements des coordonnées de chaque sommet pour chaque face
            unsigned int s_value;
            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                fichier >> s_value; //< Lecture du '3' nous indiquant qu'il y a bien trois valeur (inutile de le traiter car nous ne travaillons qu'avec des faces triangulaires)
                fichier >> s_value;
                tab_face[i].setS_one(s_value);

                fichier >> s_value;
                tab_face[i].setS_two(s_value);

                fichier >> s_value;
                tab_face[i].setS_three(s_value);
            }

            // Fermeture du fichier ouvert en lecture
            fichier.close();

            clock_fin_lecture = (double)clock()/CLOCKS_PER_SEC;

            clock_debut = (double)clock()/CLOCKS_PER_SEC; //< Récupération du temps écoulé depuis le début du programme

            #pragma omp for
            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                tab_face[i].setSeg_one( tab_point->calc_length( tab_face[i].getS_one(), tab_face[i].getS_two() )); //< Calcul de la longueur AB
                tab_face[i].setSeg_two( tab_point->calc_length( tab_face[i].getS_two(), tab_face[i].getS_three() ) );  //< Calcul de la longueur BC
                tab_face[i].setSeg_three( tab_point->calc_length( tab_face[i].getS_three(), tab_face[i].getS_one() ) ); //< Calcul de la longueur CA

                // Calcul de l'aire totale de l'objet 3D Maillé : il s'agit ici d'ajouter l'aire de chaque face à l'aire totale
                mesh.setFull(mesh.getFull() + tab_face[i].calc_area(tab_face[i].getSeg_one(), tab_face[i].getSeg_two(), tab_face[i].getSeg_three()) );
            }
            #pragma omp barrier

            std::cout << "Aire totale de la forme : " << mesh.getFull() << std::endl;
            std::cout << "Nombre de points : " << mesh.getNumberof_p() << std::endl;
            std::cout << "Nombre de faces : " << mesh.getNumberof_f() << std::endl;
        }
        else
            std::cerr << "Impossible d'ouvrir le fichier " << name_fichier << " !" << std::endl;

    }while(!is_here);

    clock_fin = (double)clock()/CLOCKS_PER_SEC; //< Récupération du temps écoulé depuis le début depuis le début du programme

    // Suppression des tableaux de Faces et de Points
    delete [] tab_face;
    delete [] tab_point;

    // Affichage du temps de calcul
    std::cout << "Temps de calcul : " <<  clock_fin - clock_debut << " s"<< std::endl;
    //---> La différence des deux clock nous permet de connaître précisement (et seulement) le temps d'éxecution des calculs. En oubliant ainsi le temps passé sur la lecture.
    //---> Dans une clock, le temps que met l'utilisateur pour entrer une valeur au clavier jusqu'à la pression de la touche "Entrée" (Return) n'est pas décompté.
    std::cout << "Temps de lecture : "<< clock_fin_lecture - clock_debut_lecture << " s"<< std::endl;
    std::cout << "Temps d'éxecution total : " << (clock_fin - clock_debut) + (clock_fin_lecture - clock_debut_lecture) << " s" << std::endl;

    return 0;
}
