#include "WeatherLog.h"
#include "WeatherRecCollector.h"
#include "Math.h"
#include "Utilities.h"
#include "Vector.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    ifstream sourcefile( "data/data_source.txt" );
    if( !sourcefile )
    {
        std::cout << "Data file was not found. Program cannot run. " << std::endl;
        return -1;
    }

    string fileName;
    WeatherLog wlog; //WindData object on stack

    while (getline(sourcefile, fileName))
    {
        ifstream infile ("data/"+fileName);
            if ( !infile) return -1;
        cout << "[DEBUGGING] Current fileName: " << fileName << '\n';
        try {
        infile >> wlog; //read from infile into W
        } catch (std::invalid_argument)
        {
            cout << "[DEBUGGING] File not read. " << endl;
        }
        infile.close();
    }
    sourcefile.close(); //close data_source.txt

    int choice = 0;
    string tempStr;
    int tempYear, tempMonth;
    float tempTotal = 0;
    float tempMean = 0;
    float tempSD;
    Vector<float> tempFloatVector;
    WeatherRecCollector wc;

    while (choice!=5)//option 5 quits
    {
        DisplayMenu();
        cin >> tempStr;

        try {
            choice = stoi(tempStr); //converts user input to integer
        } catch (const std::invalid_argument & e) { //catches if non-integer is entered
        cout << "You have entered a string! "; }

        if ( (choice<1) || (choice >5) ) //if choice is out of range
        {
            cout << "Selection invalid! Please input a number between 1-5. " << '\n';
            choice = 0; //reset choice
        }

        switch (choice) {
            case 1:
                tempYear = InputYear();
                tempMonth = InputMonth();
                wlog.Collect(tempYear, tempMonth);
                wc.GetWind(tempFloatVector); //call w object
                tempMean = calcMean(tempFloatVector);
                tempSD = calcStandardDeviation(tempFloatVector);
                Option1(tempYear, tempMonth, tempMean, tempSD); //prints values to screen
                wc.ResetVector(tempFloatVector); //clear collector and tempFloatVector
                break;
            case 2:
                tempYear = InputYear();
                for (int i=1; i<13; i++)
                {
                    wlog.Collect(tempYear, i);
                    wc.GetTemp(tempFloatVector);
                    tempMean = calcMean(tempFloatVector);
                    tempSD = calcStandardDeviation(tempFloatVector);
                    Option2(i, tempMean, tempSD);
                    wc.ResetVector(tempFloatVector);
                }
                break;
            case 3:
                tempMonth = InputMonth();

//                //applies to all years
//                //print spcc
                break;
            case 4:
                tempYear = InputYear();
                Option4(wlog, tempYear);
                break;
            case 5:
                //breaks and exits (choice = 5)
                std::cout << '\n' << "You have exited the program. Goodbye" << '\n';
                break;
            default:
                break;
        } //end switch
    }
    return 0;
}

