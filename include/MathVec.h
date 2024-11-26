#ifndef MATHVEC_H
#define MATHVEC_H

#include <cmath>

class MathVec {
private:
    double x;
    double y;

public:
    MathVec(double x, double y);
    explicit MathVec(double x); // double x oder double y als argument ist das gleiche
    MathVec();
    
    MathVec add(const MathVec &vec);
    double getAngle();
    double getMagnitude();
    double getX();
    double getY();
};


#endif //MATHVEC_H
