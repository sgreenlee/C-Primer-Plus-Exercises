// C Primer Plus
// Chapter 10 Exercise 13:

// Write a program that prompts the user to enter three sets of five double
// numbers each. (You may assume the user responds correctly and doesn’t enter
// non-numeric data.) The program should accomplish all of the following:
// a. Store the information in a 3×5 array.
// b. Compute the average of each set of five values.
// c. Compute the average of all the values.
// d. Determine the largest value of the 15 values.
// e. Report the results.
// Each major task should be handled by a separate function using the
// traditional C approach to handling arrays. Accomplish task “b” by using a
// function that computes and returns the average of a one-dimensional array;
// use a loop to call this function three times. The other tasks should take
// the entire array as an argument, and the functions performing tasks “c” and
// “d” should return the answer to the calling program.

#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

double compute_row_average(double array[COLUMNS]);
double compute_array_average(double (*array)[COLUMNS], int rows);
double largest_value(double (*array)[COLUMNS], int rows);

int main(void)
{
	double data[ROWS][COLUMNS];

	for (int i = 0; i < ROWS; i++)
	{
		printf("Enter set of %d doubles: ", COLUMNS);
		for (int j = 0; j < COLUMNS; j++)
		{
			scanf("%lf", data[i] + j);
		}
	}

	// print row averages
	printf("Row Averages:\n");
	for (int i = 0; i < ROWS; i++)
	{
		printf("\tAverage for row %d: %.3f\n", i + 1, compute_row_average(data[i]));
	}

	// print array average
	printf("Average for entire array: %.3f\n", compute_array_average(data, ROWS));

	// print largest value
	printf("Maximum array value: %.3f\n", largest_value(data, ROWS));

	return 0;
}

double compute_row_average(double array[COLUMNS])
{
	double total = 0;
	for (int i = 0; i < COLUMNS; i++)
		total += array[i];

	return total / COLUMNS;
}

double compute_array_average(double (*array)[COLUMNS], int rows)
{
	double total = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < COLUMNS; j++)
			total += array[i][j];

	return total / (rows * COLUMNS);
}

double largest_value(double (*array)[COLUMNS], int rows)
{
	double max = array[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < COLUMNS; j++)
			if (array[i][j] > max)
				max = array[i][j];

	return max;
}