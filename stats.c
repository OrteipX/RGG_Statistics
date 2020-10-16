/* Program Name: stats.c
 * Purpose: reads number pairs from file or keyboard then calculates minimum value,
 * maximum value, median value, arithmetic mean, mean absolute deviation – (mean, median, mode),
 * variance (of a discrete random variable), standard deviation (of a finite population), mode,
 * least squares regression line and outliers(2x and 3x)
 * Coder: Ramon Gnan Garcia - 0926596
 * Version: 1.0
 * Date: Feb 28, 2020
 */

#include "array_t.h"
#include "math_calc.h"
#include "print.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char* argv[])
{
    FILE* stream = stdin;

    // testing args from cmd line input
    // file or keyboard input
    if (argc > 2)
    {
        printf("Error, too many args %d\n.", argc);
        return 1;
    }
    else if (argc == 2)
    {
        stream = fopen(argv[1], "r");

        if (stream == NULL)
        {
            printf("Error %s\n", argv[1]);
            return 1;
        }
    }

    // print to the screen
    printf("Enter a list of comma-separated real number pairs terminated by EOF or nun numeric input.\n\n");

    // declaring some variables
    double num1 = 0, num2 = 0;
    array_t numbersX = array();
    array_t numbersY = array();
    char ch = 0;

    // while to read the numbers and store in arrays
    while ((fscanf(stream, "%lf%c%lf", &num1, &ch, &num2)) == 3)
    {
        array_push_back(&numbersX, num1);
        array_push_back(&numbersY, num2);

    }

    // close file
    fclose(stream);

    // sorting arrays - quick sort
    quick_sort(&numbersX, &numbersY, 0, numbersX.size - 1);

    // calculation
    double minX = min_value(&numbersX);
    double minY = min_value(&numbersY);
    double maxX = max_value(&numbersX);
    double maxY = max_value(&numbersY);
    double meanX = mean_value(&numbersX);
    double meanY = mean_value(&numbersY);
    double medianX = median_value(&numbersX);
    double medianY = median_value(&numbersY);
    array_t modeArrayX = array();
    size_t modeX = mode_value(&numbersX, &modeArrayX);
    array_t modeArrayY = array();
    size_t modeY = mode_value(&numbersY, &modeArrayY);
    double varianceX = variance(&numbersX, meanX);
    double varianceY = variance(&numbersY, meanY);
    double stdDevX = std_deviation(varianceX);
    double stdDevY = std_deviation(varianceY);
    double absMeanX = absolute_deviation(&numbersX, meanX);
    double absMeanY = absolute_deviation(&numbersY, meanY);
    double absMedianX = absolute_deviation(&numbersX, medianX);
    double absMedianY = absolute_deviation(&numbersY, medianY);
    double absModeX = modeX > 0 ? absolute_deviation_about_mode(&numbersX, &modeArrayX) : 0;
    double absModeY = modeY > 0 ? absolute_deviation_about_mode(&numbersY, &modeArrayY) : 0;
    double sumMeanXY = sum_mean_x_y_product(&numbersX, &numbersY);
    double sumMeanXPow2 = sum_mean_x_pow2(&numbersX);
    double b = slope(meanX, meanY, sumMeanXY, sumMeanXPow2);
    double a = y_intercept(b, meanX, meanY);
    double yAtMidX = y_at_mid_x(&numbersX);
    double yAtMidY = y_at_mid_y(a, b, yAtMidX);
    array_t twoOutlierArr = array();
    array_t threeOutlierArr = array();
    size_t twoOutCount = 0;
    size_t threeOutCount = 0;
    outliers(&numbersX, &numbersY, &twoOutlierArr, &threeOutlierArr, meanY, stdDevY, &twoOutCount, &threeOutCount);

    // print data
    printf("\nResults:\n" \
            "---------------------------------------------------------------------------------\n");

    print_num_elements(numbersX.size, numbersY.size);
    print_min(minX, minY);
    print_max(maxX, maxY);
    print_mean(meanX, meanY);
    print_median(medianX, medianY);
    print_mode(modeX, modeY, &modeArrayX, &modeArrayY);
    print_mode_numbers(modeX, modeY, &modeArrayX, &modeArrayY);
    print_variance(varianceX, varianceY);
    print_std_deviation(stdDevX, stdDevY);
    printf("mean absolute deviations:\n");
    print_abs_mean(absMeanX, absMeanY);
    print_abs_median(absMedianX, absMedianY);
    print_abs_mode(absModeX, absModeY);
    print_regression_line(b, a);
    print_y_at_mid_x(yAtMidX, yAtMidY);
    print_outliers(&twoOutlierArr, &threeOutlierArr, twoOutCount, threeOutCount);

    // free arrays
    array_free(&numbersX);
    array_free(&numbersY);
    array_free(&modeArrayX);
    array_free(&modeArrayY);
    array_free(&twoOutlierArr);
    array_free(&threeOutlierArr);

    return 0;
}
