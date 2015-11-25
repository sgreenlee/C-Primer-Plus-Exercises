// C Primer Plus
// Chapter 10 Exercise 2:

// Write a program that initializes an array-of-double and then copies the
// contents of the array into three other arrays. (All four arrays should be
// declared in the main program.) To make the first copy, use a function with
// array notation. To make the second copy, use a function with pointer
// notation and pointer incrementing. Have the first two functions take as
// arguments the name of the target array, the name of the source array, and
// the number of elements to be copied. Have the third function take as
// arguments the name of the target, the name of the source, and a pointer to
// the element following the last element of the source.

#include <stdio.h>
#define LENGTH 5

// prototype declarations
void copy_arr(double *target, double *source, int arr_len); // copy with array notation
void copy_ptr(double *target, double *source, int arr_len); // copy with pointer notation
void copy_ptrs(double *target, double *source_start, double *source_end); // copy with two pointers

int main(void)
{
	double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[LENGTH];
	double target2[LENGTH];
	double target3[LENGTH];

	// copy arrays
	copy_arr(target1, source, LENGTH);
	copy_ptr(target2, source, LENGTH);
	copy_ptrs(target3, source, source + LENGTH);

	// print array contents
	printf("%15s|%15s|%15s\n", "target1", "target2", "target3");
	for (int i = 0; i < LENGTH; i++)
		printf("%15.3f|%15.3f|%15.3f\n", target1[i], target2[i], target3[i]);

	return 0;
}

void copy_arr(double *target, double *source, int arr_len)
{
	// copy array using array notation

	for (int i = 0; i < arr_len; i++)
	{
		target[i] = source[i];
	}
}

void copy_ptr(double *target, double *source, int arr_len)
{
	// copy array using pointer notation

	for (int i = 0; i < arr_len; i++)
	{
		*(target + i) = *(source + i);
	}
}

void copy_ptrs(double *target, double *source_start, double *source_end)
{
	// copy arr using pointer notation and pointer endpoint

	for (double *ptr = source_start; ptr < source_end; ptr++, target++)
		*target = *ptr;
}
