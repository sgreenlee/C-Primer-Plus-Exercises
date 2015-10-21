// C Primer Plus
// Chapter 6 Exercise 14:

// Write a program that creates two eight-element arrays of doubles and uses a
// loop to let the user enter values for the eight elements of the first array.
// Have the program set the elements of the second array to the cumulative totals
// of the elements of the first array. For example, the fourth element of the
// second array should equal the sum of the first four elements of the first
// array, and the fifth element of the second array should equal the sum of the
// first five elements of the first array. (It’s possible to do this with nested
// loops, but by using the fact that the fifth element of the second array equals
// the fourth element of the second array plus the fifth element of the first
// array, you can avoid nesting and just use a single loop for this task.)
// Finally, use loops to display the contents of the two arrays, with the first
// array displayed on one line and with each element of the second array displayed
// below the corresponding element of the first array.

#include <stdio.h>

int main(void)
{
	int int_array[8], cumulative_sum[8];
	int sum = 0;

	printf("Enter 8 integers:\n");
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &int_array[i]);
		sum += int_array[i];
		cumulative_sum[i] = sum;
	}
	printf("\n");
	// display loops
	printf("      Integers:");
	for (int i = 0; i < 8; i++)
	{
		printf("%6d ", int_array[i]);
	}
	printf("\n");
	printf("Cumulative sum:");
	for (int i = 0; i < 8; i++)
	{
		printf("%6d ", cumulative_sum[i]);
	}
	printf("\n");

	return 0;
}
