#include "WeatherLog.h"
WeatherLog::WeatherLog()
{
    //Date
    //Time
    //wrecMap m_wind_data
}

void WeatherLog::Insert(int index, WeatherRecType &wrec)
{
    m_wind_data[index].Insert(wrec); //bst's insert
}

void WeatherLog::Collect(int year, int month)
{
    //filter by month's map
    WeatherRecCollector::SetYear(year);
    m_wind_data[month].InOrder(WeatherRecCollector::CollectWRec); //collect all from the month
}

void WeatherLog::PrintAll()
{
    for (wrecMap::cmItr citr = m_wind_data.Begin(); citr!=m_wind_data.End(); citr++)
    {
        citr->second.InOrder(); //default; prints
    }
}

ostream & operator<<(ostream & os, const WeatherLog & weatherlog)
{
    for (int i=1; i<13; i++)
    {
        //citr->second.InOrder(); //default calls std::cout; need a function pointer pass to pass to OS
    }
    return os;
}

istream & operator>>(istream & input, WeatherLog & weatherlog)
{
    const char DELIMITER = ',';
    string dummy;
    string tempString;
    WeatherRecType tempWRec; //creates a temp obj for inserting
    Date tempDate; //temp Date to pass by reference into array

    getline(input, tempString);
    tempWRec.SetIndexAll(tempString); //find and stores index inside WRec

    while (input.peek()!=EOF && input>>tempWRec) //reads data into rectype obj
    {
        if (tempWRec.GetSolarRadiation()>=0) //check if data is valid
        {
            tempWRec.GetDate(tempDate);
            weatherlog.Insert(tempDate.GetMonth(), tempWRec); //insert into bst
        }
    }
    try { getline(input, dummy);
    } catch (const std::runtime_error & e) {
        std::cout<<"[DEBUG] The file was not read properly" << '\n';
    }
    //tempBst.InOrder();
    //weatherlog.Insert(1, tempBst);
    return input; //return completed weatherlog to main
}
