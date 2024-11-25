#include "MathVec.h"

MathVec::MathVec(double x, double y) : x(x), y(y) {}

MathVec::MathVec() : x(0), y(0) {}


void MathVec::add(const MathVec &vec) {
    this->x += vec.x;
    this->y += vec.y;
}

double MathVec::getAngle() {
    return atan2(this->y, this->x)*180/M_PI;
}

double MathVec::getMagnitude() {
    return sqrt(this->x * this->x + this->y * this->y);
}

