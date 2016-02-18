// C Primer Plus
// Chapter 17 Exercise 6:

// Write a function that takes three arguments: the name of an array of sorted
// integers, the number of elements of the array, and an integer to seek. The
// function returns the value 1 if the integer is in the array, and 0 if it
// isn’t. Have the function use the binary search technique.

// compile with binary_search.c

#include <stdio.h>
#include "binary_search.h"

int main(void)
{
	// binarysearch()

	int arr[10] = {1, 4, 6, 9, 11, 12, 15, 19, 25, 40};

	for (int i = 0; i < 15; i++)
	{
		printf("%d in array? %s\n", i, binarysearch(arr, 10, i) ? "yes" : "no");
	}
}