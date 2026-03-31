#include "WeatherRecCollector.h"

int WeatherRecCollector::i = 0;
int WeatherRecCollector::year = 1970;
Vector<WeatherRecType> WeatherRecCollector::m_wrecArr;

void WeatherRecCollector::CollectWRec(WeatherRecType &wrec)
{
    Date tempDate;
    wrec.GetDate(tempDate);
    if (tempDate.GetYear() == year)
    {
        m_wrecArr.Add(wrec);
        //std::cout<<m_wrecArr[i]; //DEBUG
        i++;
    }

}

int WeatherRecCollector::GetVectorSize()
{
    return m_wrecArr.Size();
}

void WeatherRecCollector::ResetVector(Vector<float> &tempVector)
{
    WeatherRecCollector::m_wrecArr.Clear();
    WeatherRecCollector::i=0;
    tempVector.Clear();
}

WeatherRecType& WeatherRecCollector::operator[] (int k)
{
    return m_wrecArr[k];
}

void WeatherRecCollector::SetYear(int year)
{
    WeatherRecCollector::year = year;
}

void WeatherRecCollector::GetWind(Vector<float> &tempVector)
{
    WeatherRecCollector wc;
    for (int i=0; i<wc.GetVectorSize(); i++)
    {
        tempVector.Add(wc[i].GetSpeed());
    }
}

void WeatherRecCollector::GetTemp(Vector<float> &tempVector)
{
    WeatherRecCollector wc;
    for (int i=0; i<wc.GetVectorSize(); i++)
    {
        tempVector.Add(wc[i].GetTemperature());
    }
}

void WeatherRecCollector::GetSolar(Vector<float>& tempVector)
{
    WeatherRecCollector wc;
    for (int i=0; i<wc.GetVectorSize(); i++)
    {
        tempVector.Add(wc[i].GetSolarRadiation());
    }
}
