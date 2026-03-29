#include "Utilities.h"

void DisplayMenu()
{
    std::cout << "----------------------------------" << '\n'
              << "| Murdoch Sensor Data Calculator |" << '\n'
              << "----------------------------------" << '\n' << '\n';
    std::cout << "Option 1: Average & Standard Deviation for Wind Speed" << '\n';
    std::cout << "Option 2: Average & Standard Deviation for Ambient Air Temperature" << '\n';
    std::cout << "Option 3: Total yearly Solar Radiation" << '\n';
    std::cout << "Option 4: Output summary to WindTempSolar.csv" << '\n';
    std::cout << "Option 5: Exit program" << '\n';

    std::cout << '\n' << "Enter your choice: ";
}

void Option1(int year, int month, float mean, float sd)
{
    //print out in format (Month/Year: Data)
    std::cout << FormatMonth(month) << " ";
    std::cout << year << ": ";
    if (sd>0) //checks for valid input data
    {
        std::cout << '\n' << "Mean: " << mean << " km/h" << '\n';
        std::cout << "Sample stdev: " << sd << '\n';
    } else
    {
        std::cout << "No data found " << '\n';
    }
}

void Option2(int month, float mean, float sd)
{
    std::cout << FormatMonth(month) << ": ";
    if (sd>0) //checks for valid input data
    {
        std::cout << "Average: " << mean << " degrees Celsius "; //" C ";
        std::cout << "Stdev: " << sd << '\n';
    } else
    {
        std::cout << "No data found " << '\n';
    }
}

void Option3(int month, float total)
{
    std::cout << FormatMonth(month) << ": ";
    if (total>0) //checks for valid input data
    {
        std::cout << total << " kWh/m^2 " << '\n';
    } else
    {
        std::cout << "No data found " << '\n';
    }
}

void Option4(WeatherLog wlog, int year)
{
    //wlog. call function from inside
    Date tempDate;
    std::ofstream ofile ("WindTempSolar.csv");
    if ( !ofile) throw std::runtime_error("Output file was not created successfully. ");

    ofile << year << '\n';
    for (int i=1; i<=12; i++) //each month
    {
        ofile << FormatMonth(i) << ",";
        if (wlog.WindStandardDeviation(year, i)>0) { //validation
            ofile << wlog.WindMean(year, i)
            << "(" << wlog.WindStandardDeviation(year, i) << "),";
        } else {
            ofile << " " << ","; }
        if (wlog.TemperatureStandardDeviation(year, i)>0) { //validation
            ofile << wlog.TemperatureMean(year, i)
            << "(" << wlog.TemperatureStandardDeviation(year, i) << "),";
        } else {
            ofile << " " << ","; }
        if (wlog.SolarRadSum(year, i)>0) { //validation
            ofile << wlog.SolarRadSum(year, i) << '\n';
        } else {
            ofile << " " << '\n'; }
    }
    std::cout << "---File saved!--" << '\n';
}

int InputYear()
{
    string tempStr;
    int tempYear;
    std::cout << "Please enter a year (YYYY): " << '\n';
    std::cin >> tempStr;
        try {
            tempYear = stoi(tempStr); //converts user input to integer
        } catch (const std::invalid_argument & e) { //catches if non-integer is entered
        std::cout << "You have entered a string! ";
        tempYear = 0; } //reset year
    return tempYear;
}

int InputMonth()
{
    string tempStr;
    int tempMonth;
    std::cout << "Please enter a month  (MM): " << '\n';
    std::cin >> tempStr;
        try {
            tempMonth = stoi(tempStr); //converts user input to integer
        } catch (const std::invalid_argument & e) { //catches if non-integer is entered
        std::cout << "You have entered a string! ";
        tempMonth = 0; } //reset month
    return tempMonth;
}


string PrintDateDMY(int day, int month, int year)
{
    string tempDay = std::to_string(day);
    string tempMonth = FormatMonth(month); //initialize tempMonth to write month name (English)
    string tempYear = std::to_string(year);
    return "  Date    : " + tempDay + " " + tempMonth + " " + tempYear; //formatting for printing by os
}

string FormatMonth(int month)
{
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default:
            //month passed in should not be outside of 1-12
            std::cout<<"Invalid Month" <<'\n';
            break;
    }
    return " ";
}
