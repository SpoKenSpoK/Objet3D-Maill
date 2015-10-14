/*  Projet de Système: "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016    *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL               *
*               - Programmation séquentielle -                 */

#include <iostream>
#include <fstream>
#include "mesh.hpp"
#include "face.hpp"
#include "point.hpp"

int main()
{
    ///Création des instances.
    Face* tab_face;
    Point* tab_point;

    std::string name_fichier;
    bool ONDA_VITAL = true;

    do{
        std::cout<<"Entrez le nom du fichier .off a tester: "<<std::endl;
        std::cin>>name_fichier;

        ///Ouverture du fichier en lecture
        std::ifstream fichier(name_fichier.c_str(), std::ios::in);

        ///Test pour savoir si le fichier est bien présent
        if(fichier)
        {
            ONDA_VITAL = false;
            /// On se place au quatrième octet dans le fichier, ici après le "OFF"
            fichier.seekg(4, fichier.beg);

            int length_point;
            int length_face;
            ///Lit le nombre de points présents dans le fichier
            fichier >> length_point >> length_face;
            tab_point = new Point[length_point];
            tab_face = new Face[length_face];

            /// On vient se placer à la ligne évitant le '0'
            fichier.seekg(3, fichier.cur);

            double _temp;
            for(int i=0; i<length_point; ++i){
                fichier >> _temp;
                tab_point[i].setP_one(_temp);

                fichier >> _temp;
                tab_point[i].setP_two(_temp);

                fichier >> _temp;
                tab_point[i].setP_three(_temp);
            }

            ///Effectuer une séparation de la lecture des Faces / Points

            for(int i=0; i<length_face; ++i){
                fichier >> _temp;
                tab_face[i].setS_one(_temp);

                fichier >> _temp;
                tab_face[i].setS_two(_temp);

                fichier >> _temp;
                tab_face[i].setS_three(_temp);
            }

            ///DEBUG:
            std::cout<<length_point<<std::endl;
            std::cout<<length_face<<std::endl;



            std::cout<<tab_point[0].getP_one()<<std::endl;
            std::cout<<tab_point[0].getP_two()<<std::endl;
            std::cout<<tab_point[0].getP_three()<<std::endl;
            std::cout<<tab_point[1].getP_one()<<std::endl;
            ///





            ///Appel des fonctions membres




            ///Fermeture du fichier
            fichier.close();
        }
        else
            std::cerr<<"Impossible d'ouvrir le fichier "<<name_fichier<<" !"<<std::endl;

    }while(ONDA_VITAL);

    ///Suppression des tableaux de Faces et de Points
    delete [] tab_face;
    delete [] tab_point;

    return 0;
}
