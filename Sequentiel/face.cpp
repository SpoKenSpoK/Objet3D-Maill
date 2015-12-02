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
double Face::calc_area(){
    this->setPerimeter( ( this->getSeg_one() + this->getSeg_two() + this->getSeg_three() )/2 ); // p = 1/2 (a+b+c)
    this->setArea(  sqrt( this->getPerimeter()  * ( this->getPerimeter() - this->getSeg_one() ) // Aire = sqrt( p * (p-a)*(p-b)*(p-c) )
                                                * ( this->getPerimeter() - this->getSeg_two() )
                                                * ( this->getPerimeter() - this->getSeg_three() ) ));

    return this->getArea();
}
