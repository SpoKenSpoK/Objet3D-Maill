/**
@file main.cpp
*/

/* Projet de Système: "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016   *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL              *
*               - Programmation séquentielle -                */

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "mesh.hpp"
#include "face.hpp"
#include "point.hpp"

int main()
{
    ///Création des pointeurs pour les tableaux.
    Face* tab_face; /**< Création d'un tableau de face*/
    Point* tab_point;

    double clock_debut;
    double clock_fin;

    std::string name_fichier;
    bool is_here = false; /// sert a effectuer le while tant que le fichier n'est pas renseigné

    do{
        std::cout<<"Entrez le nom du fichier .off a tester: "<<std::endl;
        std::cin>>name_fichier;

        ///Ouverture du fichier en lecture
        std::ifstream fichier(name_fichier.c_str(), std::ios::in);

        ///Test pour savoir si le fichier est bien présent
        if(fichier)
        {
            is_here = true;

            /// On se place au quatrième octet dans le fichier (en partant du début), ici après le "OFF"
            fichier.seekg(4, fichier.beg);

            ///Lit le nombre de points présents dans le fichier
            unsigned int point_count, face_count;
            fichier >> point_count >> face_count;

            Mesh mesh(point_count, face_count);

            tab_point = new Point[mesh.getNumberof_p()];
            tab_face = new Face[mesh.getNumberof_f()];

            /// On vient se placer à la ligne évitant le '0' (en partant de la dernière position du curseur)
            fichier.seekg(3, fichier.cur);

            ///Lecture des coordonnées de chaque sommet
            double p_value;
            for(unsigned int i=0; i<mesh.getNumberof_p(); ++i){
                fichier >> p_value;
                tab_point[i].setP_one(p_value);

                fichier >> p_value;
                tab_point[i].setP_two(p_value);

                fichier >> p_value;
                tab_point[i].setP_three(p_value);
            }

            ///Lecture des emplacements des coordonnées
            int s_value;
            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                fichier >> s_value;
                fichier >> s_value;
                tab_face[i].setS_one(s_value);

                fichier >> s_value;
                tab_face[i].setS_two(s_value);

                fichier >> s_value;
                tab_face[i].setS_three(s_value);
            }

            ///Fermeture du fichier
            fichier.close();

            ///Appel des fonctions membres

            ///On calcul pour chaque face les segments
            ///Racine carré de [ (xB - xA)² + (yB - yA)² + (zB - zA)² ]
            ///Récupération du temps au debut du calcul
            clock_debut = (double)clock()/CLOCKS_PER_SEC;

            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                tab_face[i].setSeg_one( tab_point->calc_length(tab_face[i].getS_one(), tab_face[i].getS_two()) ); //Calcul de la longueur AB
                tab_face[i].setSeg_two( tab_point->calc_length(tab_face[i].getS_two(), tab_face[i].getS_three()) );  //Calcul de la longueur BC
                tab_face[i].setSeg_three( tab_point->calc_length(tab_face[i].getS_three(), tab_face[i].getS_one()) ); //Calcul de la longueur CA

               mesh.setFull(mesh.getFull() + tab_face[i].calc_area(tab_face[i].getSeg_one(), tab_face[i].getSeg_two(), tab_face[i].getSeg_three()) );
            }

            std::cout<<"Aire totale de la forme : "<<mesh.getFull()<<std::endl;
        }
        else
            std::cerr<<"Impossible d'ouvrir le fichier "<<name_fichier<<" !"<<std::endl;

    }while(!is_here);

    ///Récupération du temps a la fin du calcul
    clock_fin = (double)clock()/CLOCKS_PER_SEC;

    ///Suppression des tableaux de Faces et de Points
    delete [] tab_face;
    delete [] tab_point;

    ///Affichage du temps de calcul
    std::cout << "Temps de calcul : " <<  clock_fin - clock_debut << " s";
    ///Le temps de la saisie du nom du fichier ainsi que la lecture du fichier n'est pas prise en compte

    return 0;
}
