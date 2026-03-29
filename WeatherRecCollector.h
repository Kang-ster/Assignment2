#ifndef WEATHERRECCOLLECTOR_H_INCLUDED
#define WEATHERRECCOLLECTOR_H_INCLUDED

#include "WeatherRecType.h"
#include "Bst.h"
#include "Vector.h"
#include <iostream>
using std::vector;

class WeatherRecCollector{
public:
    static void CollectWRec(WeatherRecType &wrec);
    int GetVectorSize();
    void ResetVector();
    WeatherRecType& operator[] (int k);

private:
    static int i;
    static Vector<WeatherRecType> m_wrecArr;
};
#endif // WEATHERRECCOLLECTOR_H_INCLUDED
