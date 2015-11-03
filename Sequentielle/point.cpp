#include <iostream>
#include <math.h>
#include "point.hpp"

//Constructeur & Destructeur
Point::Point() {}
Point::~Point() {}

//Getter & Setter
double Point::getP_one() const { return point_one; }
double Point::getP_two() const { return point_two; }
double Point::getP_three() const { return point_three; }

void Point::setP_one(const double& _one) { point_one = _one; }
void Point::setP_two(const double& _two) { point_two = _two; }
void Point::setP_three(const double& _three) { point_three = _three; }

//Methodes
//Calcul d'une longueur d'un segment d'une face suivant les coordonnées de deux sommets
double Point::calc_length(unsigned int x, unsigned int y) {
    return sqrt(    pow((   ( this[y].getP_one() ) - ( this[x].getP_one()) ), 2)   //< x2 - x1
                  + pow((   ( this[y].getP_two() ) - ( this[x].getP_two()) ), 2)   //< y2 - y1
                  + pow((   ( this[y].getP_three() ) - ( this[x].getP_three()) ), 2) );    //< z2 - z1
}




