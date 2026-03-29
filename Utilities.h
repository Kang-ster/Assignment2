#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include "Vector.h"
#include "WeatherLog.h"
#include "WeatherRecType.h"

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cin;
using std::cout;

void DisplayMenu();
void Option1(int year, int month, float mean, float sd);
void Option2(int month, float mean, float sd);
void Option3(int month, float total);
void Option4(WeatherLog wlog, int year);
int InputYear();
int InputMonth();

string PrintDateDMY(int day, int month, int year);
string FormatMonth(int month);

#endif // UTILITIES_H_INCLUDED
