# Statistics

This is a C console application to compile the following statistics on a list of real number pairs:

```
minimum value;
maximum value;
median value;
arithmetic mean;
mean absolute deviation – (mean, median, mode)
variance (of a discrete random variable);
standard deviation (of a finite population);
mode (including multi-modal lists).
least squares regression line
outliers
```

The program handles any length of list. The list is to be piped from the console, or read from a file. The list is terminated with end-of-stream (^Z) or non-numeric input.

Least Squares Formulae

    b=(n(∑▒XY)-(∑▒X)(∑▒Y))/(n(∑▒X^2 )-(∑▒X)^2 )

    a=(∑▒Y-b(∑▒X))/n

Outliers

Outliers are values that are a significant distance from the mean.  When the absolute difference between a sample and its mean exceeds the standard deviation, it is a 1x outlier.  Make a list of 2x and 3x outliers – considering the Y values, the Y mean, and the Y standard deviation.

Note!

Note that both the modes and the outliers can have multiple results.  Additionally, there can be a different number of result for the X data set, and the Y data set, but not so for the outliers as you will be reporting all the outliers as (x, y) pairs (x in the first column, matching y in the second).

## Usage
```
./stats numbers.txt
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update the tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

