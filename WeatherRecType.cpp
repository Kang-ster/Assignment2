#include "WeatherRecType.h"

WeatherRecType::WeatherRecType()
{
    //Date
    //Time
    m_speed = 0.0;
}

bool WeatherRecType::operator == (const WeatherRecType &wrec) const
{
    Date tempDate;
    wrec.GetDate(tempDate);
    Time tempTime;
    wrec.GetTime(tempTime);
    return m_d == tempDate && m_t == tempTime;
}
bool WeatherRecType::operator > (const WeatherRecType &wrec) const
{
    Date tempDate;
    wrec.GetDate(tempDate);
    Time tempTime;
    wrec.GetTime(tempTime);
    if (wrec.m_d > tempDate)
    {
        return true;
    }
    else if (tempDate == m_d && m_t > tempTime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool WeatherRecType::operator < (const WeatherRecType &wrec) const
{
    Date tempDate;
    wrec.GetDate(tempDate);
    Time tempTime;
    wrec.GetTime(tempTime);
    if (m_d < tempDate)
    {
        return true;
    }
    else if (m_d == tempDate && m_t < tempTime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void WeatherRecType::GetDate(Date & date) const
{
    date = m_d;
}

void WeatherRecType::SetDate(const Date & date)
{
    m_d = date;
}

void WeatherRecType::GetTime(Time & time) const
{
    time = m_t;
}

void WeatherRecType::SetTime(const Time & time)
{
    m_t = time;
}

float WeatherRecType::GetSpeed() const
{
    return m_speed;
}

void WeatherRecType::SetSpeed(float speed)
{
    m_speed = (speed * 3.6); //km/h (*3.6)
}

float WeatherRecType::GetTemperature() const
{
    return m_temperature;
}

void WeatherRecType::SetTemperature(float temp)
{
    m_temperature = temp;
}

float WeatherRecType::GetSolarRadiation() const
{
    return m_solar_radiation;
}

void WeatherRecType::SetSolarRadiation(float sr)
{
    if (sr>=100) //reject sr values (in W/m^2) at night
    {
        m_solar_radiation = (sr / 6 / 1000); //kWh/m^2 (/6/1000)
    }
    else if (sr>=0)
    {
        m_solar_radiation = 0; //set as no sr at night
    }
    else
    {
        m_solar_radiation = sr; //set sentinel (-1) if data is invalid
    }
}

int WeatherRecType::GetSpeedIndex()
{
    return speedIndex;
}

int WeatherRecType::GetTemperatureIndex()
{
    return temperatureIndex;
}

int WeatherRecType::GetSolarIndex()
{
    return solarIndex;
}

void WeatherRecType::SetSpeedIndex(int index)
{
    speedIndex = index;
}

void WeatherRecType::SetTemperatureIndex(int index)
{
    temperatureIndex = index;
}

void WeatherRecType::SetSolarIndex(int index)
{
    solarIndex = index;
}

void WeatherRecType::SetIndexAll(string title)
{
    std::stringstream headerStream(title);
    //std::cout << "Debug: title is " << title << "]" << std::endl;
    const char DELIMITER = ',';
    string tempString;
    for (int i=0; i<18; i++) //iterate through each column
    {
        getline(headerStream, tempString, DELIMITER);
        //check if the input corresponds to either entry
        //S -> speed, T -> temp, SR -> solar radiation
        //data is assigned using setters for abstraction & future-proofing
        //*can define ___index header name in config file to work with any configuration
        if (tempString=="S")
        {
            SetSpeedIndex(i);
        }
        if (tempString=="T")
        {
            SetTemperatureIndex(i);
        }
        if (tempString=="SR")
        {
            SetSolarIndex(i);
        }
    }
}

ostream & operator<<(ostream & os, const WeatherRecType & w)
{
    Date tempDate;
    Time tempTime;

    w.GetDate(tempDate); //pass by reference
    w.GetTime(tempTime); //pass by reference
    os << tempDate << tempTime << " " << w.GetSpeed()
    << " " << w.GetTemperature() << " " << w.GetSolarRadiation(); //removed '\n'

    return os;
}

istream & operator>>(istream & input, WeatherRecType & w)
{
    const char DELIMITER = ',';
    string tempString;
    float tempFloat;
    Date tempDate;
    Time tempTime;

    for (int i=0; i<18; i++) //WAST is array pos 0
    {
        if (i==17) //last line
        {
            getline(input, tempString); //uses null char delimiter for last entry
        } else {
            getline(input, tempString, DELIMITER);
        }
        //faulty data checking
        if (tempString == "N/A" || tempString == "") //checks for spoiled sensors or empty cell
        {
            std::cout << "Invalid data " << tempString << " was found. "
            << "Line will be rejected. " << std::endl;
            w.SetSolarRadiation(-1); //using negative SOLAR value as sentinel
            if (i!=17)
            {
                getline(input, tempString); //only tosses remaining data if it is not the last entry
            }
            return input;
        }

        if (i==0) //WAST
        {
            std::istringstream dateTimeStream(tempString);
            dateTimeStream >> tempDate; //redirect to local variables; date
            dateTimeStream >> tempTime; //time
            w.SetDate(tempDate);
            w.SetTime(tempTime);
        }
        if (i==w.GetSpeedIndex())
        {
            w.SetSpeed(stof(tempString));
        }
        if (i==w.GetTemperatureIndex())
        {
            w.SetTemperature(stof(tempString));
        }
        if (i==w.GetSolarIndex())
        {
            w.SetSolarRadiation(stof(tempString)); //m_solar_radiation is in KWh/m2
        }
    }

    return input;
}
