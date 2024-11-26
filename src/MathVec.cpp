#include "MathVec.h"

MathVec::MathVec(double x, double y) : x(x), y(y) {}

MathVec::MathVec(double x) : x(x), y(0) {}

MathVec::MathVec() : x(0), y(0) {}


MathVec MathVec::add(const MathVec &vec) {
    return {this->x += vec.x, this->y += vec.y};
}

double MathVec::getAngle() {
    return atan2(this->y, this->x)*180/M_PI;
}

double MathVec::getMagnitude() {
    return sqrt(this->x * this->x + this->y * this->y);
}

