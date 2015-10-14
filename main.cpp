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

            int temp;
            ///Lit le nombre de points présents dans le fichier
            fichier >> temp;
            tab_point = new Point[temp];
            std::cout<<temp<<std::endl;

            ///Lit le nombre de face présentes dans le fichier
            fichier >> temp;
            tab_face = new Face[temp];
            std::cout<<temp<<std::endl;

            /// On vient se placer à la ligne évitant le '0'
            fichier.seekg(3, fichier.cur);

            double _temp;
            fichier >> _temp;
            tab_point[0].setP_one(_temp);

            fichier >> _temp;
            tab_point[0].setP_two(_temp);

            fichier >> _temp;
            tab_point[0].setP_three(_temp);

            fichier >> _temp;
            tab_point[1].setP_one(_temp);

            ///DEBUG:
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
