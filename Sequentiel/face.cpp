#include <iostream>
#include <math.h>
#include "face.hpp"

//Constructeur & Destructeur
Face::Face() {}
Face::~Face() {}

//Getters sommets
unsigned int Face::getS_one() const { return summit_one; }
unsigned int Face::getS_two() const { return summit_two; }
unsigned int Face::getS_three() const { return summit_three; }
//Getters segments
double Face::getSeg_one() const { return segment_one; }
double Face::getSeg_two() const { return segment_two; }
double Face::getSeg_three() const { return segment_three; }
//Getters perimetre
double Face::getPerimeter() const { return perimeter; }
//Getters aire
double Face::getArea() const { return area; }

//Setteur sommets
void Face::setS_one(const unsigned int& _one) { summit_one = _one; }
void Face::setS_two(const unsigned int& _two) { summit_two = _two; }
void Face::setS_three(const unsigned int& _three) { summit_three = _three; }
//Setteur segments
void Face::setSeg_one(const double& s_one) { segment_one = s_one; }
void Face::setSeg_two(const double& s_two) { segment_two = s_two; }
void Face::setSeg_three(const double& s_three) { segment_three = s_three; }
//Setteur perimetre
void Face::setPerimeter(const double& _perimeter) { perimeter = _perimeter; }
//Setteur aire
void Face::setArea(const double& _area) { area = _area; }

//Utilisation de la formule d'Héron :
double Face::calc_area(double AB, double BC, double CA){
    this->setPerimeter(( AB + BC + CA )/2); //< Division du périmètre par 2 comme convenu dans la formule
    this->setArea( sqrt(this->getPerimeter()*(this->getPerimeter()-AB)*(this->getPerimeter()-BC)*(this->getPerimeter()-CA)) ); //< On effectue ensuite le calcul sous la racine carré
    return this->getArea(); //< On retourne ici l'aire respective du triangle
}


