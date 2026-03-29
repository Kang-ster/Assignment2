#include "WeatherRecCollector.h"

int WeatherRecCollector::i = 0;
Vector<WeatherRecType> WeatherRecCollector::m_wrecArr;

void WeatherRecCollector::CollectWRec(WeatherRecType &wrec)
{
    m_wrecArr.Add(wrec);
    //print to test
    Date tempd;
    wrec.GetDate(tempd);
    std::cout << "DEBUG: current day " << tempd.GetDay() << " was added to the arr" << std::endl;
}

int WeatherRecCollector::GetVectorSize()
{
    return m_wrecArr.Size();
}

void WeatherRecCollector::ResetVector()
{
    m_wrecArr.Clear();
}

WeatherRecType& WeatherRecCollector::operator[] (int k)
{
    return m_wrecArr[k];
}
