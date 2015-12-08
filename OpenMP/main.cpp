/* Projet de Système: "Calcul de surface d'un objet 3D maillé" *
*   IUT d'Arles - Département Informatique - Année 2015/2016   *
*   Réalisé par Guillaume BOEHM & Thibault HECKEL              *
*               - Programmation OpenMP -                */

#include <iostream>
#include <fstream>
#include "../Sequentiel/mesh.hpp"
#include "../Sequentiel/face.hpp"
#include "../Sequentiel/point.hpp"
#include <omp.h>
#include <cstdlib>

#define NUM_THREADS 8
// Défini le nombre de threads à utiliser dans les balises parallèles

int main()
{
    Face* tab_face;
    Point* tab_point;


    std::string name_file;
    bool is_here = false;

    do{
        std::cout << "Entrez le nom du fichier .off a tester: " << std::endl;
        std::cin >> name_file;
        name_file+=".off";

        std::ifstream file(name_file.c_str(), std::ios::in);
        if(file)
        {
            is_here = true;
            file.seekg(4, file.beg);
            unsigned int point_count = 0;
            unsigned int face_count = 0;
            file >> point_count >> face_count;
            Mesh mesh(point_count, face_count);
            tab_point = new Point[mesh.getNumberof_p()];
            tab_face = new Face[mesh.getNumberof_f()];
            file.seekg(3, file.cur);

            double p_value;
            for(unsigned int i=0; i<mesh.getNumberof_p(); ++i){
                file >> p_value;
                tab_point[i].setP_one(p_value);

                file >> p_value;
                tab_point[i].setP_two(p_value);

                file >> p_value;
                tab_point[i].setP_three(p_value);
            }

            unsigned int s_value;
            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                file >> s_value;
                file >> s_value;
                tab_face[i].setS_one(s_value);

                file >> s_value;
                tab_face[i].setS_two(s_value);

                file >> s_value;
                tab_face[i].setS_three(s_value);
            }
            file.close();

            #pragma omp parallel num_threads(NUM_THREADS)
            {
                #pragma omp for
                for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                tab_face[i].setSeg_one( tab_point->calc_length( tab_face[i].getS_one(), tab_face[i].getS_two() ));
                tab_face[i].setSeg_two( tab_point->calc_length( tab_face[i].getS_two(), tab_face[i].getS_three() ) );
                tab_face[i].setSeg_three( tab_point->calc_length( tab_face[i].getS_three(), tab_face[i].getS_one() ) );
                }
            }

            for(unsigned int i=0; i<mesh.getNumberof_f(); ++i){
                mesh.setFull(mesh.getFull()+tab_face[i].calc_area());

                if(i==mesh.getNumberof_f()-1)
                    std::system("../Sequentiel/./grepmod");
            }

            std::cout << "\nNombre de sommets : "       << mesh.getNumberof_p() << std::endl;
            std::cout << "Nombre de faces : "           << mesh.getNumberof_f() << std::endl;
            std::cout << "Aire totale de la forme : "   << mesh.getFull()<<std::endl;
        }
        else std::cerr << "\nImpossible d'ouvrir le fichier : " << name_file << " !" << std::endl;

    }while(!is_here);

    delete [] tab_face;
    delete [] tab_point;

    return 0;
}
