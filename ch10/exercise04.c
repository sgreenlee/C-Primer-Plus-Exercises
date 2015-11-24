// C Primer Plus
// Chapter 10 Exercise 4:

// Write a function that returns the index of the largest value stored in an
// array-of-double. Test the function in a simple program.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int index_of_max(double *arr, int arr_size);

int main(void)
{
	// test index_of_max

	printf("Driver for index_of_max: returns index of the largest value stored "
		   "in an array of doubles.\n");
	putchar('\n');

	double test[SIZE];

	srand(time(NULL)); // seed random number generator

	// initialize test array with random doubles
	for (int i = 0; i < SIZE; i++)
		test[i] = rand() / (double) RAND_MAX;

	// print test array

	printf("%5s ", "Index");
	for (int i = 0; i < SIZE; i++)
		printf("| %6d ", i);
	printf("\n");
	printf("%5s ", "Value");
	for (int i = 0; i < SIZE; i++)
		printf("| %6.4f ", test[i]);
	printf("\n");
	printf("\n");

	// print results 
	printf("The maximum value occurs at index %d\n", index_of_max(test, SIZE));

	return 0;
}

int index_of_max(double *arr, int arr_size)
{
	// return index of max value in array of doubles

	int index_of_max = 0;
	for (int i = 1; i < arr_size; i++)
		if (*(arr + i) > *(arr + index_of_max))
			index_of_max = i;

	return index_of_max;
}