/* Program Name: array_t.c
 * Purpose: implementation for the array_t file
 * Author: Garth
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#include "array_t.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Method Name: array()
 * Purpose: it works like a constructor
 * Accepts: nothing
 * Returns: nothing
 * Date: Feb 28, 2020
 */
array_t array()
{
    array_t array = { NULL, 0, 0 };
    return array;
}

/*
 * Method Name: array_push_back()
 * Purpose: increment the array that has been passed and populates it
 * Accepts: array_t*, double
 * Returns: bool
 * Date: Feb 28, 2020
 */
bool array_push_back(array_t* arr, double number)
{
    // check if size is equal to capacity
    if (arr->size == arr->capacity)
    {
        // double the capacity
        size_t newCapacity = arr->capacity * 2;

        // if 0 increment capacity
        if (newCapacity == 0)
            ++newCapacity;

        // realloc
        double* newBlock = (double*)realloc(arr->data, newCapacity * sizeof(double));

        // if anything went wrong return false
        if (newBlock == NULL)
            return false;

        // add new block to the array
        // store new capacity
        arr->data = newBlock;
        arr->capacity = newCapacity;
    }

    // populate the array and increase the size
    arr->data[arr->size] = number;
    ++arr->size;

    return true;
}

/*
 * Method Name: array_free()
 * Purpose: this method frees an array passed as reference
 * Accepts: array_t*
 * Returns: void
 * Date: Feb 28, 2020
 */
void array_free(array_t* arr)
{
    free(arr->data);
    *arr = array();
}

/*
 * Method Name: swap_numbers()
 * Purpose: this method swap numbers passaed as reference to the method
 * Accepts: double*, double*
 * Returns: void
 * Date: Feb 28, 2020
 */
void swap_numbers(double* x, double* y)
{
    double tmp = *x;
    *x = *y;
    *y = tmp;
}

/*
 * Method Name: split_array()
 * Purpose: this method separates the values from the array
 * Accepts: array_t*, array_t*, int, int
 * Returns: int
 * Date: Feb 28, 2020
 */
int split_array(array_t* arr, array_t* parArr, int low, int high)
{
    double pivot = arr->data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr->data[j] <= pivot)
        {
            ++i;
            swap_numbers(&arr->data[i], &arr->data[j]);
            swap_numbers(&parArr->data[i], &parArr->data[j]);
        }
    }

    swap_numbers(&arr->data[i + 1], &arr->data[high]);
    swap_numbers(&parArr->data[i + 1], &parArr->data[high]);

    return (i + 1);
}

/*
 * Method Name: quick_sort()
 * Purpose: this method sort the array passed as reference and its parallel array to not
 * lose the parity
 * Accepts: array_t*, array_t*, int, int
 * Returns: void
 * Date: Feb 28, 2020
 */
void quick_sort(array_t* arr, array_t* parArr, int low, int high)
{
    if (low < high)
    {
        int sp = split_array(arr, parArr, low, high);

        quick_sort(arr, parArr, low, sp - 1);
        quick_sort(arr, parArr, sp + 1, high);
    }
}
