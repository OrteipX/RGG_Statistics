/* Program Name: print.c
 * Purpose: implementation for printing values
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#include "print.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Method Name: print_num_elements()
 * Purpose: this method prints the number of elements in the array
 * Accepts: size_t, size_t
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_num_elements(size_t num_elementsX, size_t num_elementsY)
{
    printf("%-40s%20lu%20lu\n","# elements", num_elementsX, num_elementsY);
}

/*
 * Method Name: print_min
 * Purpose: this method prints the minimum values from the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_min(double minX, double minY)
{
    printf("%-40s%20.3lf%20.3lf\n","minimum", minX, minY);
}

/*
 * Method Name: print_max()
 * Purpose: this method prints the maximum values from X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_max(double maxX, double maxY)
{
    printf("%-40s%20.3lf%20.3lf\n","maximum", maxX, maxY);
}

/*
 * Method Name: print_mean()
 * Purpose: this method prints the mean values from the X and Y values
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_mean(double meanX, double meanY)
{
    printf("%-40s%20.3lf%20.3lf\n","mean", meanX, meanY);
}

/*
 * Method Name: print_median
 * Purpose: this method prints the median values from the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_median(double medianX, double medianY)
{
    printf("%-40s%20.3lf%20.3lf\n","median", medianX, medianY);
}

/*
 * Method Name: print_mode()
 * Purpose: this method prints the mode (numbers frquency)
 * Accepts: size_t, size_t, array_t*, array_t*
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_mode(size_t modeX, size_t modeY, array_t* arrayX, array_t* arrayY)
{
    printf("%-40s", "mode");

    if (modeX == 0)
        printf("%20s", "no mode");
    else
        printf("%19s%lu", "freq.= ", (size_t)arrayX->data[0]);

    if (modeY == 0)
        printf("%20s\n", "no mode");
    else
        printf("%19s%lu\n", "freq.= ", (size_t)arrayY->data[0]);

}

/*
 * Method Name: print_mode_numbers()
 * Purpose: this method prints the frequent numbers
 * Accepts: size_t, size_t, array_t*, array_t*
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_mode_numbers(size_t modeX, size_t modeY, array_t* arrayX, array_t* arrayY)
{
    if (modeX > 0 && modeY > 0)
    {
        for (size_t i = 1; i < arrayX->size; ++i)
        {
                printf("%60.3lf", arrayX->data[i]);
                if (i < arrayY->size)
                {
                    printf("%20.3lf\n", arrayY->data[i]);
                }
                else
                {
                    printf("\n");
                }
        }
    }
    else if (modeX > 0 && modeY == 0)
    {
        for (size_t i = 1; i < arrayX->size; ++i)
        {
                printf("%60.3lf\n", arrayX->data[i]);
        }
    }
    else if (modeX == 0  && modeY > 0)
    {
        for (size_t i = 1; i < arrayY->size; ++i)
        {
                printf("%80.3lf\n", arrayY->data[i]);
        }
    }
    else
    {
        printf("\n");
    }

}

/*
 * Method Name: print_variance()
 * Purpose: this method prints the variance numbers from the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_variance(double varianceX, double varianceY)
{
    printf("%-40s%20.3lf%20.3lf\n","variance", varianceX, varianceY);
}

/*
 * Method Name: print_std_deviation()
 * Purpose: this method prints the standard deviation values from the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_std_deviation(double stdDevX, double stdDevY)
{
    printf("%-40s%20.3lf%20.3lf\n","std. dev.", stdDevX, stdDevY);
}

/*
 * Method Name: print_abs_mean()
 * Purpose: this method prints the absolute mean values from the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_abs_mean(double absMeanX, double absMeanY)
{
    printf("%-40s%20.3lf%20.3lf\n","-> about the mean", absMeanX, absMeanY);
}

/*
 * Method Name: print_abs_method()
 * Purpose: this method prints the absolute median values from the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_abs_median(double absMedianX, double absMedianY)
{
    printf("%-40s%20.3lf%20.3lf\n","-> about the median", absMedianX, absMedianY);
}

/*
 * Method Name: print_abs_mode()
 * Purpose: this method prints the absolute mode about mode values from X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_abs_mode(double absModeX, double absModeY)
{
    if (absModeX > 1 && absModeY > 1)
        printf("%-40s%20s%20s\n","-> about the mode", "multi-modal", "multi-modal");
    else if (absModeX > 1 && absModeY == 0)
        printf("%-40s%20s%20s\n","-> about the mode", "multi-modal", "no mode");
    else if (absModeX == 0 && absModeY > 1)
        printf("%-40s%20s%20s\n","-> about the mode", "no mode", "multi-modal");
    else if (absModeX == 0 && absModeY == 1)
        printf("%-40s%20s%20.3lf\n","-> about the mode", "no mode", absModeY);
    else if (absModeX == 1 && absModeY == 0)
        printf("%-40s%20.3lf%20s\n","-> about the mode", absModeX, "no mode");
    else
        printf("%-40s%20s%20s\n","-> about the mode", "no mode", "no mode");
}

/*
 * Method Name: print_regression_line()
 * Purpose: this method prints the regression line from the values in the X and Y arrays
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_regression_line(double slope, double yIntercept)
{
    printf("%-40s%14s%.3lf%15s%.3lf\n", "regression line", "a = ", yIntercept, "b = ", slope);
}

/*
 * Method Name: print_y_at_mid_x()
 * Purpose: this method prints the Y at mid (x)
 * Accepts: double, double
 * Returns: void
 * Date: Feb 28, 2020
 */
void print_y_at_mid_x(double yAtMidX, double yAtMidY)
{
    printf("%-40s%20.3lf%20.3lf\n","Y at mid (X)", yAtMidX, yAtMidY);
}

/*
 * Method Name: print_outliers()
 * Purpose: this method prints the outliers values
 * Accepts: array_t*, array_t*, size_t, size_t
 * Returns: void
 * Date: Feb 28, 2020
 */
// print the outliers values
void print_outliers(array_t* twoOutArr, array_t* threeOutArr, size_t twoOutCounter, size_t threeOutCounter)
{
    if (twoOutCounter > 0)
    {
        printf("%-40s%17s%3lu\n", "Outliers(2x)", "# outliers = ", twoOutCounter);

        for (size_t i = 0; i < twoOutArr->size; ++i)
        {
            if (i % 2 == 0)
            {
                printf("%-40s%20.3lf", "", twoOutArr->data[i]);
            }
            else
            {
                printf("%20.3lf\n", twoOutArr->data[i]);
            }
        }
    }
    else
    {
        printf("%-40s%20s\n", "Outliers(2x)", "no outliers");
    }


    if (threeOutCounter > 0)
    {
        printf("%-40s%17s%3lu\n", "Outliers(3x)", "# outliers = ", threeOutCounter);

        for (size_t i = 0; i < threeOutArr->size; ++i)
        {
            if (i % 2 == 0)
            {
                printf("%-40s%20.3lf", "", threeOutArr->data[i]);
            }
            else
            {
                printf("%20.3lf\n", threeOutArr->data[i]);
            }
        }
    }
    else
    {
        printf("%-40s%20s\n", "Outliers(3x)", "no outliers");
    }

}
