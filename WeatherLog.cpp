#include "WeatherLog.h"

WeatherLog::WeatherLog()
{
    //Date
    //Time
}

void WeatherLog::GetWindData(Vector<WeatherRecType> & weatherlog) const
{
    for (int i=0; i<m_wind_data.Size(); i++){
        weatherlog.Add(m_wind_data[i]); //deep copy
    }
}

void WeatherLog::SetWindData(const Vector<WeatherRecType> & weatherlog)
{
    for (int i=0; i<weatherlog.Size(); i++){
        m_wind_data.Add(weatherlog[i]); //deep copy
    }
}

int WeatherLog::GetSize()
{
    return m_wind_data.Size();
}

//Vector<WeatherRecType> WeatherLog::GetMonthData(int year, int month)
//{
//    Date tempDate;
//    Vector<WeatherRecType> windArr;
//    //filter for year month
//    for (int i=0; i<m_wind_data.Size(); i++)
//    {
//        m_wind_data[i].GetDate(tempDate);
//        if (tempDate.GetYear()==year && tempDate.GetMonth()==month)
//            windArr.Insert(m_wind_data[i]);
//    }
//
//    return windArr;
//}

float WeatherLog::WindMean(int year, int month)
{
    Vector<float> windArr;
    Date tempDate;
    for (int i=0; i<m_wind_data.Size(); i++)
    {
        m_wind_data[i].GetDate(tempDate);
        if (tempDate.GetYear()==year && tempDate.GetMonth()==month)
        {
            windArr.Add(m_wind_data[i].GetSpeed()); //add sum of speed to array
        }
    }
    float tempMean = calcMean(windArr); //pass vector
    return tempMean;
}

float WeatherLog::WindStandardDeviation(int year, int month)
{
    Vector<float> windArr;
    Date tempDate;
    for (int i=0; i<m_wind_data.Size(); i++)
    {
        m_wind_data[i].GetDate(tempDate);
        if (tempDate.GetYear()==year && tempDate.GetMonth()==month)
        {
            windArr.Add(m_wind_data[i].GetSpeed()); //add sum of speed to array
            std::cout << "Debug: windspeed at index " << i << " is " << m_wind_data[i].GetSpeed() << std::endl;
        }
    }
    float tempSD = calcStandardDeviation(windArr); //pass vector
    return tempSD;
}

float WeatherLog::TemperatureMean(int year, int month)
{
    Vector<float> tempArr;
    Date tempDate;
    for (int i=0; i<m_wind_data.Size(); i++)
    {
        m_wind_data[i].GetDate(tempDate);
        if (tempDate.GetYear()==year && tempDate.GetMonth()==month)
        {
            tempArr.Add(m_wind_data[i].GetTemperature()); //add sum of temperature
        }
    }
    float tempMean = calcMean(tempArr);
    return tempMean;
}

float WeatherLog::TemperatureStandardDeviation(int year, int month)
{
    Vector<float> tempArr;
    Date tempDate;
    for (int i=0; i<m_wind_data.Size(); i++)
    {
        m_wind_data[i].GetDate(tempDate);
        if (tempDate.GetYear()==year && tempDate.GetMonth()==month)
        {
            tempArr.Add(m_wind_data[i].GetTemperature()); //add sum of temperature
        }
    }
    float tempSD = calcStandardDeviation(tempArr);
    return tempSD;
}

float WeatherLog::SolarRadSum(int year, int month)
{
    float total = 0;
    Date tempDate;
    for (int i=0; i<m_wind_data.Size(); i++)
    {
        m_wind_data[i].GetDate(tempDate);
        if (tempDate.GetYear()==year && tempDate.GetMonth()==month)
        {
            total += m_wind_data[i].GetSolarRadiation(); //add to array of temperature
        }
    }
    return total;
}

//bool WeatherLog::IsDupe(Vector<WeatherRecType> warr, WeatherRecType wrec)
//{
//    Date temp1;
//    Date temp2;
//    for (int i=0; i<warr.Size(); i++)
//    {
//        //check
//        warr[i].GetDate(temp1);
//        wrec.GetDate(temp2);
//        //std::cout << temp1 << "," << temp2 << std::endl;
//        //if
//        if (temp1 == temp2)
//        {
//            //std::cout<<"same day"<<std::endl;
//            return true;
//        }
//    }
//    return false;
//}

ostream & operator<<(ostream & os, const WeatherLog & weatherlog)
{
    Vector<WeatherRecType> tempWLog;
    weatherlog.GetWindData(tempWLog); //assigns weatherlog's private data to tempWLog
    for (int i=0; i<tempWLog.Size(); i++) //read tempWLog
    {
        os << tempWLog[i]; //print each object (weatherRecType)
    }
    return os;
}

istream & operator>>(istream & input, WeatherLog & weatherlog)
{
    const char DELIMITER = ',';
    string dummy;
    string tempString;
    WeatherRecType tempWRec; //creates a temp obj for inserting into vector
    Date tempDate; //temp Date to pass by reference into array
    Vector<WeatherRecType> tempWLog; //temp Vector

    getline(input, tempString);
    tempWRec.SetIndexAll(tempString); //find and stores index inside WRec

    while (input.peek()!=EOF && input>>tempWRec) //reads data into rectype obj
    {
        if (tempWRec.GetSolarRadiation()>=0) //check if data is valid
        {
            tempWRec.GetDate(tempDate);
            //insert into bst
                    //wrecmap[tempDate.GetMonth()].Add();
            //search for duplicate
            //if (!weatherlog.IsDupe(tempWLog, tempWRec))
                tempWLog.Add(tempWRec);
        }
    }

    try { getline(input, dummy);
    } catch (const std::runtime_error & e) {
        std::cout<<"[DEBUG] The file was not read properly" << '\n';
    }

    weatherlog.SetWindData(tempWLog); //assign temp Vector to current weatherlog obj
    return input; //return completed weatherlog to main
}
