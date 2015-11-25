// C Primer Plus
// Chapter 10 Exercise 08:

// Use a copy function from Programming Exercise 2 to copy the third through
// fifth elements of a seven-element array into a three-element array. The
// function itself need not be altered; just choose the right actual arguments.
// (The actual arguments need not be an array name and array size. They only
// have to be the address of an array element and a number of elements to be
// processed.)

#include <stdio.h>

void copy_ptrs(double *target, double *source_start, double *source_end);

int main(void)
{
	double source[7] = {2.4, 5.9, 7.8, 1.5, 3.3, 5.3, 6.8};
	double target[3];

	copy_ptrs(target, source + 2, source + 5);

	// print arrays
	for (int i = 0; i < 7; i++)
		printf("%.1f ", source[i]);
	putchar('\n');

	for (int i = 0; i < 3; i++)
		printf("%.1f ", target[i]);
	putchar('\n');

	return 0;
}

void copy_ptrs(double *target, double *source_start, double *source_end)
{
	// copy arr using pointer notation and pointer endpoint

	for (double *ptr = source_start; ptr < source_end; ptr++, target++)
		*target = *ptr;
}