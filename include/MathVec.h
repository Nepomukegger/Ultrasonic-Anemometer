#ifndef MATHVEC_H
#define MATHVEC_H

#include <cmath>

class MathVec {
public:
    void add(MathVec vec);
    double getAngle();
    double getMagnitude();
private:
    double x;
    double y;
};


#endif //MATHVEC_H
