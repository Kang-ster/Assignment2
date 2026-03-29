#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED
#include <cmath>
#include "Vector.h"
/** Math.h <p>
* A collection of mathematical functions for calculating statistics.
* Uses the encapsulated std Vector within Vector.h
*/
//const Vector<float> numbers
float toOneDecimal(float num);
float calcSum(Vector<float> numArr);
float calcMean(Vector<float> numArr);
float calcStandardDeviation(Vector<float> numArr);
float calcSPCC(Vector<float> numArr1, Vector<float> numArr2);
float calcMAD(Vector<float> numArr);

#endif // MATH_H_INCLUDED
