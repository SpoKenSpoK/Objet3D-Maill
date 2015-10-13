/*  Projet de Système, "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016    *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL               *
*           - Programmation séquentielle -                     */

#include <iostream>
#include <fstream>
#include "mesh.hpp"
#include "face.hpp"
#include "point.hpp"

int main()
{
    ///Ecire IHM ici
    std::string name_fichier;
    bool ONDA_VITAL = true;

    do{
        std::cout<<"Entrez le nom du fichier .off a tester: "<<std::endl;
        std::cin>>name_fichier;

        std::ifstream fichier(name_fichier.c_str(), std::ios::in); ///Ouverture du fichier en lecture
        if(fichier) ///Test pour savoir si le fichier est bien présent
        {
            ONDA_VITAL = false;
            fichier.seekg(4, fichier.beg); /// On se place au quatrième octet dans le fichier, ici après le "OFF"

            int temp;
            fichier >> temp; ///Lit le nombre de points présents dans le fichier
            //point_tab = new double[temp];
            fichier >> temp; ///Lit le nombre de faces présentes dans le fichier
            //face_tab = new double[temp];

            fichier.seekg(3, fichier.cur); /// On vient se placer à la ligne évitant le '0'

            fichier.close();
        }
        else
            std::cerr<<"Impossible d'ouvrir le fichier "<<name_fichier<<" !"<<std::endl;

    }while(ONDA_VITAL);

    return 0;
}
