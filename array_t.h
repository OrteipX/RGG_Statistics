/* Program Name: array_t.h
 * Purpose: header files for the implementation
 * Author: Garth
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#ifndef ARRAY_T_H
#define ARRAY_T_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// struct
typedef struct array_t_tag
{
    double* data;
    size_t size;
    size_t capacity;
}array_t;

// declarations
array_t array();
void array_free(array_t* array);
bool array_push_back(array_t* array, double value);
bool array_resize(array_t* array, size_t newSize);
void swap_numbers(double* x, double* y);
int split_array(array_t* array, array_t* parArray, int low, int high);
void quick_sort(array_t* array, array_t* parArray, int low, int high);

#endif

