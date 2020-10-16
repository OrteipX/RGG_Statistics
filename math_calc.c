/* Program Name: math_calc.c
 * Purpose: implementation for the math file
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#include "math_calc.h"
#include "array_t.h"
#include <float.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/*
 * Method Name: sum_mean_x_y_product()
 * Purpose: this method sum the product of X and Y values
 * Accepts: array_t*, array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double sum_mean_x_y_product(array_t* arr1, array_t* arr2)
{
    double sumMeanXY = 0;

    // loop through the whole array
    for (size_t i = 0; i < arr1->size; ++i)
        sumMeanXY += arr1->data[i] * arr2->data[i];

    return sumMeanXY / arr1->size;
}

/*
 * Method Name: sum_mean_x_pow2()
 * Purpose: this method does the sum of the x to the power of 2
 * Accepts: array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double sum_mean_x_pow2(array_t* arr)
{
    double sumMeanXPow2 = 0;

    // loop through the whole array
    for (size_t i = 0; i < arr->size; ++i)
        sumMeanXPow2 += pow(arr->data[i], 2);

    return sumMeanXPow2 / arr->size;
}

/*
 * Method Name: min_value()
 * Purpose: this method calculates the minimum value of the array passed as reference
 * Accepts: array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double min_value(array_t* arr)
{
    double min = DBL_MAX;

    for (size_t i = 0; i < arr->size; ++i)
    {
        if (arr->data[i] < min)
        {
            min = arr->data[i];
        }
    }

    return min;
}

/*
 * Method Name: max_value()
 * Purpose: this method calculates the maximum value of the array passed as reference
 * Accepts: array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
// calculates the maximum value of the array
double max_value(array_t* arr)
{
    double max = DBL_MIN;

    for (size_t i = 0; i < arr->size; ++i)
    {
        if (arr->data[i] > max)
        {
            max = arr->data[i];
        }
    }

    return max;
}

/*
 * Method Name: mean_value()
 * Purpose: this method calculates the mean value of the array values
 * Accepts: array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double mean_value(array_t* arr)
{
    double sum = 0;

    for (size_t i = 0; i < arr->size; ++i)
        sum += arr->data[i];

    return sum / arr->size;
}

/*
 * Method Name: median_value()
 * Purpose: this method calculates the median value of the array values
 * Accepts: array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double median_value(array_t* arr)
{
    if (arr->size % 2 == 0)
        return ((arr->data[arr->size / 2] + arr->data[arr->size / 2 - 1]) / 2);
    else
        return arr->data[arr->size / 2];
}

/*
 * Method Name: count_mode()
 * Purpose: this method is and aggregated method for calculatinf mode
 * Accepts: array_t*
 * Returns: size_t
 * Date: Feb 28, 2020
 */
size_t count_mode(array_t* arr)
{
    size_t counter = 1;

    for (size_t i = 0; i < arr->size; ++i)
    {
        size_t tmpCounter = 1;

        for (size_t j = i + 1; j < arr->size; ++j)
        {
            if (arr->data[i] == arr->data[j])
            {
                ++tmpCounter;
            }
            else
            {
                break;
            }
        }

        if (tmpCounter > counter)
        {
            counter = tmpCounter;
        }
    }

    return counter;
}

/*
 * Method Name: mode_value()
 * Purpose: this method calculates the mode, multi-mode and no mode
 * Accepts: array_t*, array_t*
 * Returns: size_t
 * Date: Feb 28, 2020
 */
size_t mode_value(array_t* arr, array_t* modeArray)
{
    array_t tmpModeArray = array();

    // if the number is equal to next
    // add to the tmpModeArray (number)
    // increment i
    for (size_t i = 0; i < arr->size; ++i)
    {
        for (size_t j = i + 1; j < arr->size; ++j)
        {
            if (arr->data[i] == arr->data[j])
            {
                array_push_back(&tmpModeArray, arr->data[i]);
                ++i;
            }
        }

    }

    // call the function count_mode to return the mode number
    size_t mode = count_mode(&tmpModeArray);
    // add the mode number to the modeArray
    array_push_back(modeArray, mode + 1);

    // method to check count the modes
    // add the numbers to the modeArray
    for (size_t i = 0; i < tmpModeArray.size; ++i)
    {
        size_t counter = 1;

        for (size_t j = i + 1; j < tmpModeArray.size; ++j)
        {
            if (tmpModeArray.data[i] == tmpModeArray.data[j])
            {
                ++counter;
            }
        }

        if (counter == mode)
        {
            array_push_back(modeArray, tmpModeArray.data[i]);
        }
    }

    // free array
    array_free(&tmpModeArray);


    // check for mode
    // return 0
    if (((modeArray->size - 1) * (mode + 1)) == arr->size || modeArray->size == 1)
    {
        return 0;
    }

    return 1;

}

/*
 * Method Name: variance()
 * Purpose: this method calculates the variance of the numbers in the array
 * Accepts: array_t*, double
 * Returns: double
 * Date: Feb 28, 2020
 */
double variance(array_t* arr, double mean)
{
    double sum = 0;

    for (size_t i = 0; i < arr->size; ++i)
        sum += pow((arr->data[i] - mean), 2);

    return sum / arr->size;
}

/*
 * Method Name: std_deviation()
 * Purpose: this method calculates the standard deviation having the variance
 * Accepts: double
 * Returns: double
 * Date: Feb 28, 2020
 */
// calculates the standard deviation
double std_deviation(double variance)
{
    return sqrt(variance);
}

/*
 * Method Name: absolute_deviation()
 * Purpose: this method calculates the absolute deviation of the array
 * Accepts: array_t*, double
 * Returns: double
 * Date: Feb 28, 2020
 */
double absolute_deviation(array_t* arr, double x)
{
    double sum = 0;

    for (size_t i = 0; i < arr->size; ++i)
    {
        double diff = arr->data[i] - x;
        sum += fabs(diff);
    }

    return sum / arr->size;
}

/*
 * Method Name: absolute_deviation_about_mode()
 * Purpose: this method calculates the absolute deviation about mode of the array
 * Accepts: array_t*, array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double absolute_deviation_about_mode(array_t* arr, array_t* modeArr)
{
    double sum = 0;

    for (size_t i = 0; i < arr->size; ++i)
    {
        for (size_t j = 0; j < modeArr->size; ++j)
        {
            double diff = arr->data[i] - modeArr->data[j];
            sum += fabs(diff);
        }
    }

    return sum / arr->size;
}

/*
 * Method Name: slope()
 * Purpose: this method calculates the slope from the values from X and Y arrays
 * Accepts: double, double, double, double
 * Returns: double
 * Date: Feb 28, 2020
 */
double slope(double meanX, double meanY, double sumMeanXY, double sumMeanXPow2)
{
    return ((meanX * meanY - sumMeanXY) / (pow(meanX, 2) - sumMeanXPow2));
}

/*
 * Method Name: y_intercept()
 * Purpose: this method calculates the interception point in Y
 * Accepts: double, double, double
 * Returns: double
 * Date: Feb 28, 2020
 */
// calculates the interception point in y
double y_intercept(double slope, double meanX, double meanY)
{
    return meanY - (slope * meanX);
}

/*
 * Method Name: y_at_mid_x()
 * Purpose: this method calculates the Y at mid(x)
 * Accepts: array_t*
 * Returns: double
 * Date: Feb 28, 2020
 */
double y_at_mid_x(array_t* arr)
{
     return ((arr->data[arr->size - 1] - arr->data[0]) / 2) + arr->data[0];
}

/*
 * Method Name: y_at_mid_y()
 * Purpose: this method calculates the Y at mid(y)
 * Accepts: double, double, double
 * Returns: double
 * Date: Feb 28, 2020
 */
double y_at_mid_y(double a, double b, double x)
{
     return (a + (b * x));
}

/*
 * Method Name: outliers()
 * Purpose: this method calculates the outliers from the Y array and print if exist its
 * pair
 * Accepts: array_t*, array_t*, array_t*, array_t*, double, double, size_t, size_t
 * Returns: void
 * Date: Feb 28, 2020
 */
void outliers(array_t* arrX, array_t* arrY, array_t* arrTwoOut, array_t* arrThreeOut, double meanY, double stdDevY, size_t * twoOut, size_t * threeOut)
{
    double num = 0;
    size_t twoOutliers = 0, threeOutliers = 0;

    for (size_t i = 0; i < arrX->size; ++i)
    {
        num = arrY->data[i] - meanY;
        num = fabs(num);

        if (num > (stdDevY * 2))
        {
            array_push_back(arrTwoOut, arrX->data[i]);
            array_push_back(arrTwoOut, arrY->data[i]);
            ++twoOutliers;
        }
        if (num > (stdDevY * 3))
        {
            array_push_back(arrThreeOut, arrX->data[i]);
            array_push_back(arrThreeOut, arrY->data[i]);
            ++threeOutliers;
        }
    }

    *twoOut = twoOutliers;
    *threeOut = threeOutliers;

}
