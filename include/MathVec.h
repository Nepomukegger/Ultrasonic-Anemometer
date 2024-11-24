#ifndef ULTRASONIC_ANEMOMETER_MATHVEC_H
#define ULTRASONIC_ANEMOMETER_MATHVEC_H

#include <cmath>

class MathVec {
public:
    void add(MathVec vec);
    void getAngle();
    void getMagnitude();
private:
    double x;
    double y;
};


#endif //ULTRASONIC_ANEMOMETER_MATHVEC_H
