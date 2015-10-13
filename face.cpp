#include "face.hpp"

Face::Face() {}
Face::~Face() {}

long unsigned Face::getS_one() const { return summit_one; }
long unsigned Face::getS_two() const { return summit_two; }
long unsigned Face::getS_three() const { return summit_three; }

void Face::setS_one(const long unsigned& _one) { summit_one = _one; }
void Face::setS_two(const long unsigned& _two) { summit_two = _two; }
void Face::setS_three(const long unsigned& _three) { summit_three = _three; }


