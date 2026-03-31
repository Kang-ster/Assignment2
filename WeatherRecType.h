#ifndef WEATHERRECTYPE_H_INCLUDED
#define WEATHERRECTYPE_H_INCLUDED

#include "Date.h"
#include "Time.h"
#include "Vector.h"

#include <iostream>
#include <string>
#include <sstream>

/** @class WeatherRecType
 * @brief Object to contain all values to be recorded
 *
 * m_d is object of Date class, and contains the day, month and year that the data is obtained, and is used in conjunction with Time to get the precise timing of the measurement
 *
 * m_t is object of Time class, and contains hour and minute of the data obtained (in 10min intervals). Seconds are implemented in Time class but not used for this build.
 *
 * @param m_d - Date
 * @param m_t - Time
 * @param m_speed - Wind Speed
 * @param m_temperature - Ambient Air Temperature
 * @param m_solar_radiation - Solar Radiation
 */
class WeatherRecType
{
public:
    ///Default constructor for WindData object.
    WeatherRecType();

    ///comparators for Bst
    bool operator == (const WeatherRecType &wrec) const;
    bool operator > (const WeatherRecType &wrec) const;
    bool operator < (const WeatherRecType &wrec) const;

    /** @brief Passes m_d by reference
    *
    * @param Date & d - Date object to be given reference.
    *
    * @return void
    */
    void GetDate(Date & date) const;

    /** @brief Sets m_d by reference
    *
    * @param const Date & date - Date object to pass into m_d.
    *
    * @return void
    */
    void SetDate(const Date & date);

    /** @brief Passes m_t by reference
    *
    * @param Time & time - Time object to be given reference.
    *
    * @return void
    */
    void GetTime(Time & time) const;

    /** @brief Sets m_t by reference
    *
    * @param const Time & time - Time object to pass into m_t.
    *
    * @return void
    */
    void SetTime(const Time & time);

    /** @brief Passes m_speed by float
    *
    * @return float
    */
    float GetSpeed() const;

    /** @brief Sets m_speed
    *
    * @param speed - float
    *
    * @return void
    */
    void SetSpeed(float speed);

    /** @brief Passes m_temperature by float
    *
    * @return float
    */
    float GetTemperature() const;

    /** @brief Sets m_temperature
    *
    * @param temp - float
    *
    * @return void
    */
    void SetTemperature(float temp);

    /** @brief Passes m_solar_radiation by float
    *
    * @return float
    */
    float GetSolarRadiation() const;

    /** @brief Sets m_solar_radiation
    *
    * @param sr - float
    *
    * @return void
    */
    void SetSolarRadiation(float sr);

    int GetSpeedIndex();
    int GetTemperatureIndex();
    int GetSolarIndex();
    void SetSpeedIndex(int index);
    void SetTemperatureIndex(int index);
    void SetSolarIndex(int index);
    void SetIndexAll(string title);

private:
    Date m_d;
    Time m_t;
    float m_speed;
    float m_temperature;
    float m_solar_radiation;

    int speedIndex;
    int temperatureIndex;
    int solarIndex;
};

ostream & operator<<(ostream & os, const WeatherRecType & w);
istream & operator>>(istream & input, WeatherRecType & w);
#endif // WEATHERRECTYPE_H_INCLUDED
