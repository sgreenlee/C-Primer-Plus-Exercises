// C Primer Plus
// Chapter 10 Exercise 5:

// Write a function that returns the difference between the largest and
// smallest elements of an array-of-double. Test the function in a simple
// program

#include <stdio.h>

double max_difference(double *arr, int arr_size);

int main(void)
{
	// test max difference

	double test[5] = {1.0, 3.4, 2.2, 0.9, 2.0};

	// print test results
	printf("The difference between the largest and smallest values of ");
	for (int i = 0; i < 5; i++)
		printf("%.1f ", test[i]);
	printf("is %.1f\n", max_difference(test, 5));

	return 0;
}

double max_difference(double *arr, int arr_size)
{
	// return the difference between the largest and smallest elements
	// of an array-of-double

	double max = arr[0];
	double min = arr[0];

	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}

	return max - min;
}