/*
    Projet de Système: "Calcul de surface d'un objet 3D maillé"
    IUT d'Arles - Département Informatique - Année 2015/2016
    Réalisé par Guillaume BOEHM & Thibault HECKEL
              - Programmation séquentielle -
*/

// Include --------
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mesh.hpp"
#include "face.hpp"
#include "point.hpp"
// ----------------

int main()
{
    // Déclarations des principales variables locales au main ------
    Face* tab_face;             // Création d'un pointeur sur Face qui sera par la suite associé à un tableau
    Point* tab_point;           // Création d'un pointeur sur Point qui sera lui aussi associé à un tableau
    std::string name_file;      // String récupérant le nom du file à éxecuter. Placé ainsi avant la boucle while nous évitons de le rédéclarer à chaque itération de boucle
    bool is_here = false;       // Booléen permettant d'éxecuter la boucle while ci-dessous : prend true si le file est vérifié
    // ---------------------

    do{
        std::cout << "Entrez le nom du file .off a tester: " << std::endl;
        std::cin >> name_file;
        name_file+=".off";   // Ajout de l'extension .off au nom du fichier entré précédement

        // Ouverture du fichier en lecture ----------------------
        std::ifstream file(name_file.c_str(), std::ios::in);

        if(file) // Test pour savoir si le fichier est bien présent dans le répertoire donné
        {
            is_here = true;                 // Si le fichier est vérifié alors la valeur et vraie et nous pouvons sortir de la boucle
            file.seekg(4, file.beg);        // On se place au quatrième octet dans le file (en partant du début), ici après le "OFF"

            unsigned int point_count = 0;   // Création d'un entier positif représentant le nombre de points présent dans le fichier
            unsigned int face_count = 0;    // Création d'un autre entier positif, celui-ci représentant le nombre de faces

            file >> point_count >> face_count;      // Lecture du fichier, les deux premiers entiers positifs sont insérés dans les variables précédemments définies
            Mesh mesh(point_count, face_count);     // Création d'une instance de Mesh en insérant dans le constructeur le nombre de points et faces obtenus

            tab_point = new Point[mesh.getNumberof_p()];    // Allocation dynamique du tableau de Point ayant pour taile le nombre de coordonnées
            tab_face = new Face[mesh.getNumberof_f()];      // Allocation dynamique du tableau de Face prennant comme taille le nombre de faces

            file.seekg(3, file.cur);                        // On se place à la ligne, derrière le '0'

            // ----- Lecture des coordonnées de chaque sommet ------------
            double p_value;     // Variable temporaire servant à la lecture des doubles
            /*
                Boucle for qui permet de lire la totalité des réels (coordonnées des sommets) composants le fichier .off
                Appel des différents mutateurs de la classe Point à chaque itération de boucle
                pour insérer une valeur dans les trois coordonnées du sommet 'i'
            */
            for(unsigned int i=0; i<mesh.getNumberof_p(); ++i){
                file >> p_value;
                tab_point[i].setP_one(p_value);

                file >> p_value;
                tab_point[i].setP_two(p_value);

                file >> p_value;
                tab_point[i].setP_three(p_value);
            }

            // ----- Lecture des emplacements des coordonnées de chaque sommet pour chaque face
            unsigned int s_value;   // Variable temporaire pour la lecture des entier positifs
            /*
                Boucle for qui lit la totalité des entiers positifs (emplacement - ligne) composants le fichier .off
                Appel des différents mutateurs de classe Face à chaque itération de boucle
                pour insérer le numéro de ligne auquel se trouve les coordonnées du sommet 'i'
            */
            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                file >> s_value;    /*  Lecture du '3' nous indiquant qu'il y a bien trois sommets
                                        (inutile de le traiter car nous ne travaillons qu'avec des faces triangulaires) */
                file >> s_value;
                tab_face[i].setS_one(s_value);

                file >> s_value;
                tab_face[i].setS_two(s_value);

                file >> s_value;
                tab_face[i].setS_three(s_value);
            }

            file.close(); // Fermeture du fichier
            // ---------------------------------- FIN DE LECTURE ---------------------------------------

            // -------------------------------------- CALCUL -------------------------------------------

            /*
                EXPLICATION CALCUL :

                Nous connaissons le calcul de longueur d'un côté suivant les coordonnées respectives de ses deux sommmets (extrémités).
                Nous connaissons aussi le calcul d'Héron suivant la longueur des trois côtés d'un triangle qui nous permet de calculer l'aire de celui-ci.

                Ainsi, nous effectuons d'abord une boucle for permettant de calculer pour chaque face, les trois segments qui la compose.
                Soit un triangle ABC, il nous faut calculer la longueur AB, puis BC et enfin CA.

                La méthode calc_length de la classe Point prend en paramètre la ligne où se trouvent les coordonnées x, y et z d'un premier sommet et celle d'un deuxième sommmet.
                En résumé nous avons calc_length( ligne où allez pour trouver xA, yA, zA, ligne où allez pour trouver xB, yB, zB).
                Nous obtenons donc la longueur de ses trois côtés; avec cela il nous est maintenant possible de calculer la surface du triangle.

                La méthode calc_area de la classe Face effectue la méthode d'Héron et nous retroune l'aire du triangle 'i'.
                Nous l'ajoutons alors à l'aire totale.
            */

            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                tab_face[i].setSeg_one( tab_point->calc_length( tab_face[i].getS_one(), tab_face[i].getS_two() ));          // Calcul de la longueur AB
                tab_face[i].setSeg_two( tab_point->calc_length( tab_face[i].getS_two(), tab_face[i].getS_three() ) );       // Calcul de la longueur BC
                tab_face[i].setSeg_three( tab_point->calc_length( tab_face[i].getS_three(), tab_face[i].getS_one() ) );     // Calcul de la longueur CA

                mesh.setFull( mesh.getFull() + tab_face[i].calc_area() ); // Calcul de l'aire totale : addition de l'aire de la face à l'aire totale

                if(i==mesh.getNumberof_f()-1)   // Appel le script grepmod et nous permet de connaître la RAM libre juste à la fin des calculs.
                    std::system("./grepmod");
            }

            // ----------------------------------- FIN CALCUL ------------------------------------------

            std::cout << "\nNombre de sommets : "       << mesh.getNumberof_p() << std::endl;
            std::cout << "Nombre de faces : "           << mesh.getNumberof_f() << std::endl;
            std::cout << "Aire totale de la forme : "   << mesh.getFull()<<std::endl;
        }
        else std::cerr << "\nImpossible d'ouvrir le fichier : " << name_file << " !" << std::endl;
    }while(!is_here);

    // Suppression des tableaux de Faces et de Points
    delete [] tab_face;
    delete [] tab_point;

    return 0;
}
