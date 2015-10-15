#include "face.hpp"

///Très certainement include math pour sqrt
///Pour le permimètre on return pour le moment un double mais il s'agit d'une valeur de tab_point
///Créer trois autres membres qui sont les longueurs AB, BC et CA ?

Face::Face() {}
Face::~Face() {}

long unsigned Face::getS_one() const { return summit_one; }
long unsigned Face::getS_two() const { return summit_two; }
long unsigned Face::getS_three() const { return summit_three; }
double Face::getPerimeter() const { return perimeter; }

void Face::setS_one(const long unsigned& _one) { summit_one = _one; }
void Face::setS_two(const long unsigned& _two) { summit_two = _two; }
void Face::setS_three(const long unsigned& _three) { summit_three = _three; }
void Face::setPerimeter(const double& AB, const double& BC, const double& CA) { perimeter = (AB + BC + CA); }

double Face::calc_area(double& AB, double& BC, double& CA){
///Formule Héron :
///Racine carré de (périmètre * (périmètre - AB)(périmètre - BC)(périmètre - CA)
/// https://fr.wikipedia.org/wiki/Formule_de_H%C3%A9ron?oldformat=true

this->setPerimeter(AB, BC, CA);

///Retourne l'air calculée à partir des longueurs des segments de la face
/*return Aire = sqrt this->getPerimeter()*(this->getPerimeter() - AB)*(this->getPerimeter() - BC)*(this->getPerimeter() - CA); */

///Pour debuger
return 0;
}


