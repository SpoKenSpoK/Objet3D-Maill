#include "index.hpp"
#include <fstream>

///Executer une lecture de fichier

std::string name_fichier = "Bouddha500k.off";
double* point_tab;
double* face_tab;

double read(){
    std::ifstream fichier(name_fichier.c_str(), std::ios::in);
    if(fichier) /// Si le fichier est bien ouvert en lecture
    {
        fichier.seekg(4, fichier.beg); /// On se place au quatrième octet dans le fichier, ici après le "OFF"

        int temp;
        fichier >> temp;
        point_tab = new double[temp]; ///Lit le nombre de points présents dans le fichier
        fichier >> temp;
        face_tab = new double[temp]; ///Lit le nombre de faces présentes dans le fichier

        fichier.seekg(3, fichier.cur); /// On vient se placer à la ligne évitant le '0'

        fichier.close();
    }
    else
        std::cerr<<"Impossible d'ouvrir le fichier "<<name_fichier<<" !"<<std::endl;

    return 0;
}





