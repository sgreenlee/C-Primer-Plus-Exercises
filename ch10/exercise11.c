// C Primer Plus
// Chapter 10 Exercise 11:

// Write a program that declares a 3×5 array of int and initializes it to some
// values of your choice. Have the program print the values, double all the
// values, and then display the new values. Write a function to do the
// displaying and a second function to do the doubling. Have the functions take
// the array name and the number of rows as arguments.

#include <stdio.h>

void print_Nx5_int_array(int (*array)[5], int rows);
void double_Nx5_int_array(int (*array)[5], int rows);

int main(void)
{
	int array[3][5] = {{ 2,  5,  6,  9,  1},
					   {23,  1,  5, 66, 54},
					   { 9, 73, 23, 39,  2}};

	printf("Original array:\n");
	print_Nx5_int_array(array, 3);

	// double array and print new values
	double_Nx5_int_array(array, 3);
	printf("Doubled array:\n");
	print_Nx5_int_array(array, 3);

	return 0;
}

void print_Nx5_int_array(int (*array)[5], int rows)
{
	// print the contents of an N x 5 array of ints

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf(" %5d ", array[i][j]);
		}
		putchar('\n');
	}
}

void double_Nx5_int_array(int (*array)[5], int rows)
{
	// double the elements of an N x 5 array of ints

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < 5; j++)
			array[i][j] *= 2;
}