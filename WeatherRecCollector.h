#ifndef WEATHERRECCOLLECTOR_H_INCLUDED
#define WEATHERRECCOLLECTOR_H_INCLUDED

#include "WeatherLog.h"
#include "Bst.h"
#include "Vector.h"
#include <iostream>

class WeatherRecCollector{
public:
    static void CollectWRec(WeatherRecType &wrec);
    static int GetVectorSize();
    void ResetVector(Vector<float> &tempVector);
    WeatherRecType& operator[] (int k);
    static void SetYear(int year);

    void GetWind(Vector<float>& tempVector);
    void GetTemp(Vector<float>& tempVector);
    void GetSolar(Vector<float>& tempVector);

private:
    static int i;
    static int year;
    static Vector<WeatherRecType> m_wrecArr;
};

#endif // WEATHERRECCOLLECTOR_H_INCLUDED
