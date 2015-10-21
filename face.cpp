#include <iostream>
#include <math.h>
#include "face.hpp"

///Très certainement include math pour sqrt
///Créer trois autres membres qui sont les longueurs AB, BC et CA ?

///Constructeur & Destructeur
Face::Face() {}
Face::~Face() {}

///Getter & Setter
long unsigned Face::getS_one() const { return summit_one; }
long unsigned Face::getS_two() const { return summit_two; }
long unsigned Face::getS_three() const { return summit_three; }
double Face::getSeg_one() const { return segment_one; }
double Face::getSeg_two() const { return segment_two; }
double Face::getSeg_three() const { return segment_three; }
double Face::getPerimeter() const { return perimeter; }
double Face::getArea() const { return area; }

void Face::setS_one(const long unsigned& _one) { summit_one = _one; }
void Face::setS_two(const long unsigned& _two) { summit_two = _two; }
void Face::setS_three(const long unsigned& _three) { summit_three = _three; }
void Face::setSeg_one(const double& s_one) { segment_one = s_one; }
void Face::setSeg_two(const double& s_two) { segment_two = s_two; }
void Face::setSeg_three(const double& s_three) { segment_three = s_three; }
void Face::setPerimeter(const double& _perimeter) { perimeter = _perimeter; }
void Face::setArea(const double& _area) { area = _area; }

///Utilisation de la formule d'Héron :
double Face::calc_area(double AB, double BC, double CA){
    this->setPerimeter( AB + BC + CA);
    this->setArea( sqrt(this->getPerimeter()*(this->getPerimeter()-AB)*(this->getPerimeter()-BC)*(this->getPerimeter()-CA)) );
    return this->getArea();
}


