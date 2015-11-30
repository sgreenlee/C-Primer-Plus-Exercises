// C Primer Plus
// Chapter 10 Exercise 9:

// Write a program that initializes a two-dimensional 3×5 array-of-double and
// uses a VLA- based function to copy it to a second two-dimensional array.
// Also provide a VLA-based function to display the contents of the two arrays.
// The two functions should be capable, in general, of processing arbitrary N×M
// arrays. (If you don’t have access to a VLA-capable compiler, use the
// traditional C approach of functions that can process an N×5 array).

#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

void copy_2dim_arr(int rows, int cols, double source[rows][cols],
	               double target[rows][cols]);
void print_2dim_arr(int rows, int cols, double arr[rows][cols]);

int main(void)
{
	double array1[ROWS][COLUMNS] = {{4.3, 5.7, 2.1, 6.6, .8},
						            {5.6, 23.5, 73.2, 12.3, 123},
						            {22.1, 35.3, 6.35, 0.132, 11.1}};
	double array2[ROWS][COLUMNS];

	// copy array1 to array2
	copy_2dim_arr(ROWS, COLUMNS, array1, array2);

	// print contents of arrays
	printf("Array 1:\n");
	print_2dim_arr(ROWS, COLUMNS, array1);
	putchar('\n');

	printf("Array2:\n");
	print_2dim_arr(ROWS, COLUMNS, array2);

	return 0;
}

void copy_2dim_arr(int rows, int cols, double source[rows][cols],
	               double target[rows][cols])
{
	// copy one two-dimensional array to another

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			target[i][j] = source[i][j];
		}
	}
}

void print_2dim_arr(int rows, int cols, double arr[rows][cols])
{
	// print the contents of a two-dimensional array

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf(" %10.3f ", arr[i][j]);

		putchar('\n');
	}
}
