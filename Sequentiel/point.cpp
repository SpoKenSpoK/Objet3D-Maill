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
//Calcul d'une longueur d'un segment d'une face suivant les coordonnées de deux sommets :
double Point::calc_length(unsigned int A, unsigned int B) {
    return sqrt(    pow((   ( this[B].getP_one()) -    ( this[A].getP_one()) ), 2)          //< (xB - xA)²
                  + pow((   ( this[B].getP_two()) -    ( this[A].getP_two()) ), 2)          //< (yB - yA)²
                  + pow((   ( this[B].getP_three()) -  ( this[A].getP_three()) ), 2) );     //< (zB) - zA)²
}
