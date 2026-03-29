#include "Time.h"

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
}

Time::Time(int hour, int minute)
{
    m_hour = hour;
    m_minute = minute;
}

int Time::GetHour() const
{
    return m_hour;
}

void Time::SetHour(int hour)
{
    m_hour = hour;
}

int Time::GetMinute() const
{
    return m_minute;
}

void Time::SetMinute(int minute)
{
    m_minute = minute;
}

int Time::GetSecond() const
{
    return m_second;
}
void Time::SetSecond(int second)
{
    m_second = second;
}

bool Time::operator != (const Time &t) const
{
    return m_hour != t.GetHour() && m_minute != t.GetMinute();
}

string PrintTime(int hour, int minute)
{
    string tempHour;
    string tempMinute;
    //string tempSecond;
    if (hour<10)
        tempHour = "0" + std::to_string(hour);
    else
        tempHour = std::to_string(hour);
    if (minute<10)
        tempMinute = "0" + std::to_string(minute);
    else
        tempMinute = std::to_string(minute);
    //string tempSecond = std::to_string(second);

    return "  Time: " + tempHour + ":" + tempMinute;
}

ostream & operator<<(ostream & os, const Time & time)
{
  os << PrintTime(time.GetHour(), time.GetMinute());
  return os;
}

istream & operator>>(istream & input, Time & time)
{
    const char DELIMITER = ':';
    string tempString;
    getline(input, tempString, DELIMITER);
    time.SetHour(stoi(tempString));
    getline(input, tempString, ','); //data contains only hours:minutes. comma taken by WindData obj
    time.SetMinute(stoi(tempString));
//    getline(input, tempString); //no seconds in data
//    time.SetSecond(stoi(tempString));
    return input;
}
