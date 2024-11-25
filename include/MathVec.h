#ifndef MATHVEC_H
#define MATHVEC_H

#include <cmath>

class MathVec {
public:
    MathVec(double x, double y);
    MathVec();
    void add(const MathVec &vec);
    double getAngle();
    double getMagnitude();
    double getX();
    double getY();
private:
    double x;
    double y;
};


#endif //MATHVEC_H
