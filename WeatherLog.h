#ifndef WEATHERLOG_H_INCLUDED
#define WEATHERLOG_H_INCLUDED

#include "WeatherRecType.h"
#include "Vector.h"
#include "Bst.h"
#include "Math.h"
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;


/** @class WeatherLog
 * @brief Object that contains a dynamic array of WeatherRecType objects
 *
 * @param Vector<WeatherRecType> m_wind_data - a dynamic array of WeatherRecType objects
 */
class WeatherLog
{
public:
    ///Default constructor for WindData object.
    WeatherLog();

    void GetWindData(Vector<WeatherRecType> & weatherlog) const;
    void SetWindData(const Vector<WeatherRecType> & weatherlog);

    int GetSize();
    //Vector<WeatherRecType> GetMonthData(int year, int month);

    float WindMean(int year, int month);
    float WindStandardDeviation(int year, int month);

    float TemperatureMean(int year, int month);
    float TemperatureStandardDeviation(int year, int month);

    float SolarRadSum(int year, int month);

    //bool IsDupe(Vector<WeatherRecType> warr, WeatherRecType wrec);

private:
    Vector<WeatherRecType> m_wind_data; //the vector
};

ostream & operator<<(ostream & os, const WeatherLog & weatherlog);
istream & operator>>(istream & input, WeatherLog & weatherlog);

#endif // WINDDATA_H_INCLUDED
