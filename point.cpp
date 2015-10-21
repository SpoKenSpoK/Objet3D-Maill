#include <iostream>
#include <math.h>
#include "point.hpp"

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
///Calcul d'une longueur d'un segment d'une face suivant les coordonnées de deux sommets
double Point::calc_length(double A, double B){ return sqrt(pow((B - A), 2));  }




