#ifndef WEATHERLOG_H_INCLUDED
#define WEATHERLOG_H_INCLUDED

#include "WeatherRecType.h"
#include "WeatherRecCollector.h"
#include "Vector.h"
#include "Map.h"
#include "Bst.h"
#include "Math.h"
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
//using std::map;

typedef Bst<WeatherRecType> wrecBst;
typedef Map<int, wrecBst> wrecMap;

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

    void Insert(int index, WeatherRecType &wrec);

//    cdItr Begin();
//    cdItr End();
    int GetSize();

    //collector functions
    void Collect(int year, int month);
    void PrintAll();

private:
    wrecMap m_wind_data; //container
};

ostream & operator<<(ostream & os, const WeatherLog & weatherlog);
istream & operator>>(istream & input, WeatherLog & weatherlog);

#endif // WINDDATA_H_INCLUDED
