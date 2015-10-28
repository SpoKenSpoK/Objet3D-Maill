#include "mesh.hpp"

//Constructeur & Destructeur
Mesh::Mesh(long unsigned point, long unsigned face)
    :numberof_point(point), numberof_face(face)
{}

Mesh::~Mesh() {}

//Getter & Setter
long unsigned Mesh::getNumberof_p() const { return numberof_point; }
void Mesh::setNumberof_p(const long unsigned& point) { numberof_point = point; }

long unsigned Mesh::getNumberof_f() const { return numberof_face; }
void Mesh::setNumberof_f(const long unsigned& face) { numberof_face = face; }



