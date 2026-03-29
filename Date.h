#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

/** @class Date
 * @brief Date the data was acquired.
 *
 * Date is part of the WindData class. It contains the day, month and year that the data is obtained, and is used in conjunction with Time to get the precise timing of the measurement
 *
 * @param m_day - Day
 * @param m_month - Month
 * @param m_year - Year
 */
class Date
{
public:
    /** @brief Default constructor. Initializes day, month and year.
    */
    Date();
    Date(int day, int month, int year);

    bool operator == (const Date &d) const;
    bool operator > (const Date &d) const;
    bool operator < (const Date &d) const;

    /** @brief Gets the Day
    *
    * @return m_day - Day
    */
    int GetDay() const;

    /** @brief Sets the Day
    *
    * @param day - name to be passed into m_day
    *
    * @return void
    */
    void SetDay(int day);

    /** @brief Gets the Month
    *
    * @return m_month - Month
    */
    int GetMonth() const;

    /** @brief Sets the Month
    *
    * @param month - name to be passed into m+month
    *
    * @return void
    */
    void SetMonth(int month);

    /** @brief Gets the Year
    *
    * @return m_year - Year
    */
    int GetYear() const;

    /** @brief Sets the Year
    *
    * @param year - name to be passed into m_year
    *
    * @return void
    */
    void SetYear(int year);

private:
    int m_day;
    int m_month;
    int m_year;
};

/**
 * @brief Takes in the date and prints it into DD/Month/YYYY format
 * @param day - Day
 * @param month - Month
 * @param year - Year
 */

ostream & operator<<(ostream & os, const Date & date);
istream & operator>>(istream & input, Date & date);

#endif // DATE_H
