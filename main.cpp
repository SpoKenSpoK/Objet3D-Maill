/*  Projet de Système: "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016    *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL               *
*               - Programmation séquentielle -                 */

#include <iostream>
#include <fstream>
#include "mesh.hpp"
#include "face.hpp"
#include "point.hpp"


/// NE MARCHE PAS AVEC SPHERE6.OFF par exemple, lecture de double pour les coordonnées ne marche pas quand on tombe sur un int

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

            ///Lecture des coordonnées de chaque sommet
            double p_value;
            for(int i=0; i<length_point; ++i){
                fichier >> p_value;
                tab_point[i].setP_one(p_value);

                fichier >> p_value;
                tab_point[i].setP_two(p_value);

                fichier >> p_value;
                tab_point[i].setP_three(p_value);
            }

            ///Lecture des emplacements des coordonnées
            int s_value;
            for(int i=0; i<length_face; ++i){
                fichier >> s_value;
                fichier >> s_value;
                tab_face[i].setS_one(s_value);

                fichier >> s_value;
                tab_face[i].setS_two(s_value);

                fichier >> s_value;
                tab_face[i].setS_three(s_value);
            }
            /*
            ///DEBUG:
            std::cout<<"Nombre de points: "<<length_point<<std::endl;
            std::cout<<"Nombre de face: "<<length_face<<std::endl;

            std::cout<<"Coordonne x du premier point(sommet): "<<tab_point[0].getP_one()<<std::endl;
            std::cout<<"Coordonne z du dernier point(sommet): "<<tab_point[length_point-1].getP_three()<<std::endl;

            std::cout<<"Ligne ou se situe les coordonnes du premier sommet de la premiere face: "<<tab_face[0].getS_one()<<std::endl;
            std::cout<<"Ligne ou se situe les coordonnes du dernier sommet de la derniere face: "<<tab_face[length_face-1].getS_three()<<std::endl;

            std::cout<<"Coordonnes x, y et z du premier sommet de la face numéro 1 (0 dans le tableau): "
            <<tab_point[tab_face[0].getS_one()-3].getP_one()<<" "
            <<tab_point[tab_face[0].getS_one()-3].getP_two()<<" "
            <<tab_point[tab_face[0].getS_one()-3].getP_three()<<std::endl;
            ///*/

            ///Appel des fonctions membres

            ///On calcul pour chaque face les segments
            ///Racine carré de [ (xB - xA)² + (yB - yA)² + (zB - zA)² ]
            double FULL_AREA;

            for(int i=0; i<length_face; ++i){
                double temp = tab_point->calc_length( tab_point[tab_face[i].getS_one()-3].getP_one(), tab_point[tab_face[i].getS_two()-3].getP_one() );      /// Calcul de sqrt(xB - xA)²
                double tamp = tab_point->calc_length( tab_point[tab_face[i].getS_one()-3].getP_two(), tab_point[tab_face[i].getS_two()-3].getP_two() );      /// Calcul de sqrt(yB - yA)²
                double tomp = tab_point->calc_length( tab_point[tab_face[i].getS_one()-3].getP_three(), tab_point[tab_face[i].getS_two()].getP_three() );    /// Calcul de sqrt(zB - zA)²
                tab_face[i].setSeg_one(temp+tamp+tomp);     ///Longueur AB

                temp = tab_point->calc_length( tab_point[tab_face[i].getS_two()-3].getP_one(), tab_point[tab_face[i].getS_three()-3].getP_one() );      /// Calcul de sqrt(xC - xB)²
                tamp = tab_point->calc_length( tab_point[tab_face[i].getS_two()-3].getP_two(), tab_point[tab_face[i].getS_three()-3].getP_two() );      /// Calcul de sqrt(yC - yB)²
                tomp = tab_point->calc_length( tab_point[tab_face[i].getS_two()-3].getP_three(), tab_point[tab_face[i].getS_three()].getP_three() );    /// Calcul de sqrt(zC - zB)²
                tab_face[i].setSeg_two(temp+tamp+tomp);     ///Longueur BC

                temp = tab_point->calc_length( tab_point[tab_face[i].getS_three()-3].getP_one(), tab_point[tab_face[i].getS_one()-3].getP_one() );      /// Calcul de sqrt(xA - xC)²
                tamp = tab_point->calc_length( tab_point[tab_face[i].getS_three()-3].getP_two(), tab_point[tab_face[i].getS_one()-3].getP_two() );      /// Calcul de sqrt(yA - yC)²
                tomp = tab_point->calc_length( tab_point[tab_face[i].getS_three()-3].getP_three(), tab_point[tab_face[i].getS_one()].getP_three() );    /// Calcul de sqrt(zA - zC)²
                tab_face[i].setSeg_three(temp+tamp+tomp);   ///Longueur CA

                //tab_face[i].calc_area(tab_face[i].getSeg_one(), tab_face[i].getSeg_two(), tab_face[i].getSeg_three());
                FULL_AREA+=tab_face[i].calc_area(tab_face[i].getSeg_one(), tab_face[i].getSeg_two(), tab_face[i].getSeg_three());
            }
            std::cout<<"FULL_AREA : "<<FULL_AREA<<std::endl;
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
