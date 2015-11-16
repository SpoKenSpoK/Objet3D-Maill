#include "mesh.hpp"

//Constructeur
Mesh::Mesh(unsigned int point, unsigned int face, double area)
    :numberof_point(point), numberof_face(face), FULL_AREA(0)
{}

Mesh::Mesh()
    :numberof_point(0), numberof_face(0)
{}

//Destructeur
Mesh::~Mesh() {}

//Getters
unsigned int Mesh::getNumberof_p() const { return numberof_point; }
unsigned int Mesh::getNumberof_f() const { return numberof_face; }
double Mesh::getFull() const { return FULL_AREA; }

//Setters
void Mesh::setNumberof_p(const unsigned int& point) { numberof_point = point; }
void Mesh::setNumberof_f(const unsigned int& face) { numberof_face = face; }
void Mesh::setFull(const double& area) { FULL_AREA = area; }



