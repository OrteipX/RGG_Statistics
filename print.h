/* Program Name: print.h
 * Purpose: header file which contains the methods signatures for printing
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#ifndef PRINT_H
#define PRINT_H

#include "array_t.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void print_num_elements(size_t num_elementsX, size_t num_elementsY);
void print_min(double minX, double minY);
void print_max(double maxX, double maxY);
void print_mean(double meanX, double meanY);
void print_median(double medianX, double medianY);
void print_mode(size_t modeX, size_t modeY, array_t* arrayX, array_t* arrayY);
void print_mode_numbers(size_t modeX, size_t modeY, array_t* arrayX, array_t* arrayY);
void print_variance(double varianceX, double varianceY);
void print_std_deviation(double stdDevX, double stdDevY);
void print_abs_mean(double absMeanX, double absMeanY);
void print_abs_median(double absMedianX, double absMedianY);
void print_abs_mode(double absModeX, double absModeY);
void print_regression_line(double slope, double yIntercept);
void print_y_at_mid_x(double yAtMidX, double yAtMidY);
void print_outliers(array_t* twoOutArr, array_t* threeOutArr, size_t twoOutCounter, size_t threeOutCounter);

#endif

