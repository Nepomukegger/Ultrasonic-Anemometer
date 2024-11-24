#include "MathVec.h"

void add(MathVec vec) {
    this.x += vec.x;
    this.y += vec.y;
}

void getAngle() {
    return atan2(this.y, this.x)*180/M_PI;
}

void getMagnitude() {
    return sqrt(this.x * this.x + this.y * this.y);
}

