#include "mesh.hpp"

//Constructeur
Mesh::Mesh(long unsigned point, long unsigned face)
    :numberof_point(point), numberof_face(face)
{}

//Destructeur
Mesh::~Mesh() {}

//Getters
long unsigned Mesh::getNumberof_p() const { return numberof_point; }
long unsigned Mesh::getNumberof_f() const { return numberof_face; }

//Setters
void Mesh::setNumberof_p(const long unsigned& point) { numberof_point = point; }
void Mesh::setNumberof_f(const long unsigned& face) { numberof_face = face; }



