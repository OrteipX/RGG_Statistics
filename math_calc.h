/* Program Name: math_calc.h
 * Purpose: header files containing the method signatures for math file
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#ifndef MATH_CALC_H
#define MATH_CALC_H

#include "array_t.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

double sum_mean_x_y_product(array_t* arr1, array_t* arr2);
double sum_mean_x_pow2(array_t* arr1);
double min_value(array_t* arr);
double max_value(array_t* arr);
double mean_value(array_t* arr);
double median_value(array_t* arr);
size_t count_mode(array_t* arr);
size_t mode_value(array_t* arr, array_t* modeArr);
double variance(array_t* arr, double mean);
double std_deviation(double variance);
double absolute_deviation(array_t* arr, double x);
double absolute_deviation_about_mode(array_t* arr, array_t* modeArr);
double slope(double meanX, double meanY, double sumMeanXY, double sumMeanXPow2);
double y_intercept(double slope, double meanX, double meanY);
double y_at_mid_x(array_t* arr);
double y_at_mid_y(double a, double b, double x);
void outliers(array_t* arrX, array_t* arrY, array_t* arrTwoOut, array_t* arrThreeOut, double meanY, double stdDevY, size_t * twoOut, size_t * threeOut);

#endif

