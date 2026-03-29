#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

/** @class Time
 * @brief Timestamp of the data.
 *
 * Time is part of the WindData class. It contains the hours and minutes of the timestamp.
 * Hours are stored in 24hr format.
 *
 * @param m_hour - Hour
 * @param m_minute - Minute
 */

class Time
{
public:
    /** @brief Default constructor. Initializes hours and minutes.
    */
    Time();
    Time(int hour, int minute);

    int GetHour() const;
    void SetHour(int hour);

    int GetMinute() const;
    void SetMinute(int minute);

    int GetSecond() const;
    void SetSecond(int second);

    bool operator != (const Time &t) const;

private:
    int m_hour;
    int m_minute;
    int m_second;
};

string PrintTime(int hour, int minute);
ostream & operator<<(ostream & os, const Time & time);
istream & operator>>(istream & input, Time & time);
#endif // TIME_H_INCLUDED
