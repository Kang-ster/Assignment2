#include "Math.h"
#include <iostream>
using namespace std;

float toOneDecimal(float num)
{
    //add .5
    //trunc
    //return
}

float calcSum(Vector<float> numArr)
{
    float total = 0;
    for (int i=0; i<numArr.Size(); i++)
    {
        total += numArr[i];
    }
    return total;
}

float calcMean(Vector<float> numArr)
{
    float tempTotal = calcSum(numArr);
    return (tempTotal/numArr.Size());
}

float calcStandardDeviation(Vector<float> numArr)
{
    float term = 0;
    float tempSD = 0;
    float mean = calcMean(numArr);
    for (int i=0; i<numArr.Size(); i++) {
        term = (numArr[i] - mean); //find difference from mean
        term *= term; //square the difference
        tempSD += term; //cumulative sum
    }
    //mean of means
    tempSD /= numArr.Size(); //variance
    //square root of variance
    tempSD = sqrt(tempSD); //final Standard Deviation
    return tempSD;
}

float calcSPCC(Vector<float> numArr1, Vector<float> numArr2)
{
    //both shld be same
    if (numArr1.Size()!=numArr2.Size())
    {
        std::cout << "DEBUG: the 2 arrays are different sizes" << std::endl;
        return 0;
    }
    //expected covariance is E[XY] - E[X]E[Y]
    //expected value of their product minus the product of their expected values
    float exy = 0;
    float sumx, sumy = 0;
    float sumx2 = 0;
    float sumy2 = 0;
    //calc exy
    for (int i=0; i<numArr1.Size(); i++)
    {
        sumx+=numArr1[i];
        sumx2+=(numArr1[i] * numArr1[i]);

        sumy+=numArr2[i];
        sumy2+=(numArr2[i] * numArr2[i]);

        exy+=(numArr1[i] * numArr2[i]);
    }
    std::cout<< "Sumx: " << sumx << " " << sumx2 << " sumy:" << sumy << " " << sumy2 << " Sum both " << exy << std::endl;
    float cov = (numArr1.Size() * exy) - (sumx * sumy);
    std::cout << "Numerator: " << cov;
    float deno1 = (numArr1.Size() * sumx2) - (sumx * sumx);
    float deno2 = (numArr1.Size() * sumy2) - (sumy * sumy);
    float voc = sqrt(deno1 * deno2);
    std::cout << "Denominator: " << voc;
    return cov / voc;
}

float calcMAD(Vector<float> numArr)
{
    float mad = 0;
    float mean = calcMean(numArr);
    for (int i=0; i<numArr.Size(); i++) {
        mad += abs(numArr[i] - mean); //find difference from mean (absolute) for each item
    }
    mad /= numArr.Size();
    return mad;
}
