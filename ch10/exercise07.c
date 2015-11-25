// C Primer Plus
// Chapter 10 Exercise 7:

// Write a program that initializes a two-dimensional array-of-double and uses
// one of the copy functions from exercise 2 to copy it to a second two
// dimensional array. (Because a two-dimensional array is an array of arrays, a
// one-dimensional copy function can be used with each subarray.)

#include <stdio.h>
#include <stdlib.h>

void copy_ptr(double *target, double *source, int arr_len);
void print_row(double (*arr)[10], int row);

int main(void)
{
	// copy one 10 by 10 array to another 10 by 10 array

	double source[10][10];
	double target[10][10];

	// initialize source array
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			source[i][j] = rand() / (double) RAND_MAX;

	// copy source array to target
	for (int i = 0; i < 10; i++)
		copy_ptr(target[i], source[i], 10);

	// print arrays
	printf("%-50s", "Source");
	printf("   ");
	printf("%-50s", "Target");
	putchar('\n');
	for (int i = 0; i < 103; i++)
		putchar('-');
	putchar('\n');
	for (int i = 0; i < 10; i++)
	{
		print_row(source, i);
		printf("   ");
		print_row(target, i);
		putchar('\n');
	}

	return 0;
}

void copy_ptr(double *target, double *source, int arr_len)
{
	// copy array using pointer notation

	for (int i = 0; i < arr_len; i++)
	{
		*(target + i) = *(source + i);
	}
}

void print_row(double (*arr)[10], int row)
{
	// print a row from a n by 10 array of doubles

	for (int i = 0; i < 10; i++)
	{
		printf("%.2f ", arr[row][i]);
	}
}