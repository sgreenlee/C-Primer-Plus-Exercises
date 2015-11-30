// C Primer Plus
// Chapter 10 Exercise 10:

// Write a function that sets each element in an array to the sum of the
// corresponding elements in two other arrays. That is, if array 1 has the
// values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4, and 6, the
// function assigns array 3 the values 3, 4, 9, and 14. The function should
// take three array names and an array size as arguments. Test the function in
// a simple program.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void add_arrays(int *addend1, int *addend2, int *sum, int array_length);

int main(void)
{
	// test add_arrays

	srand(time(NULL));

	int array1[SIZE];
	int array2[SIZE];
	int sum[SIZE];

	// initialize arrays with random ints
	for (int i = 0; i < SIZE; i++)
	{
		array1[i] = rand() % 20;
		array2[i] = rand() % 20;
	}

	// get sum of arrays
	add_arrays(array1, array2, sum, SIZE);

	// print arrays
	printf("%8s %8s %8s\n", "Array 1", "Array 2", "Sum");
	for (int i = 0; i < SIZE; i++)
		printf("%8d %8d %8d\n", array1[i], array2[i], sum[i]);

	return 0;
}

void add_arrays(int *addend1, int *addend2, int *sum, int array_length)
{
	// calculate elementwise sum of two arrays

	for (int *tar = sum; tar < sum + array_length; tar++, addend1++, addend2++)
		*tar = *addend1 + *addend2;
}