#include <math.h>
#include "point.hpp"
#include <iostream>

///Constructeur & Destructeur
Point::Point() {}
Point::~Point() {}

///Getter & Setter
double Point::getP_one() const { return point_one; }
double Point::getP_two() const { return point_two; }
double Point::getP_three() const { return point_three; }

void Point::setP_one(const double& _one) { point_one = _one; }
void Point::setP_two(const double& _two) { point_two = _two; }
void Point::setP_three(const double& _three) { point_three = _three; }

///Methodes
double Point::calc_length(double&, double&){ ///Calcul d'une longueur d'un segment d'une face suivant les coordonnées de deux sommets
///Racine carré de  [ (xB - xA)² + (yB - yA)² + (zB - zA) ]


    return sqrt( )
}




