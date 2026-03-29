#include "Date.h"

//contains date stored as day/ month/ year
Date::Date(){
    m_day = 1;
    m_month = 1;
    m_year = 1970;
}

Date::Date(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

int Date::GetDay() const
{
    return m_day;
}

void Date::SetDay(int day)
{
    m_day = day;
}

int Date::GetMonth() const
{
    return m_month;
}

void Date::SetMonth(int month)
{
    m_month = month;
}

int Date::GetYear() const
{
    return m_year;
}

void Date::SetYear(int year)
{
    m_year = year;
}

bool Date::operator == (const Date &d) const
{
    return m_year == d.GetYear() && m_month == d.GetMonth() && m_day == d.GetDay();
}

bool Date::operator > (const Date &d) const
{
    if (m_year > d.GetYear())
    {
        return true;
    }
    else if (m_year == d.GetYear() && m_month > d.GetMonth())
    {
        return true;
    }
    else if (m_year == d.GetYear() && m_month == d.GetMonth() && m_day > d.GetDay())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Date::operator < (const Date &d) const
{
    if (m_year < d.GetYear())
    {
        return true;
    }
    else if (m_year == d.GetYear() && m_month < d.GetMonth())
    {
        return true;
    }
    else if (m_year == d.GetYear() && m_month == d.GetMonth() && m_day < d.GetDay())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream & operator << ( ostream & os, const Date & date )
{
  os << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear();
  //os << PrintDateDMY(date.GetDay(), date.GetMonth(), date.GetYear()); //pass in date's values to be printed
  //"Date received : " << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear() << '\n';
  return os;
}

istream & operator >> (istream & input, Date & date)
{
//    if (input.peek()=='\0')
//        std::cout << "Debug worked";
    const char DELIMITER = '/';
    string tempString;
    getline(input, tempString, DELIMITER);
    date.SetDay(stoi(tempString));
    getline(input, tempString, DELIMITER);
    date.SetMonth(stoi(tempString));
    getline(input, tempString, ' '); //delimiter takes whole line for dates.txt purposes
    date.SetYear(stoi(tempString));
    return input;
}
