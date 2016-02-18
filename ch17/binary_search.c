// binary_search.c -- an implementation of binary search for an array of integers

#include "binary_search.h"

static int binarysearch_aux(int * arr, int target, int low, int high);

int binarysearch(int * arr, int arr_size, int target)
{
	return binarysearch_aux(arr, target, 0, arr_size - 1);
}


static int binarysearch_aux(int * arr, int target, int low, int high)
{
	// base case
	if (low == high)
		return arr[low] == target ? 1 : 0;

	// recursion case
	else
	{
		int mid = (low + high) / 2;
		if (arr[mid] < target)
			return binarysearch_aux(arr, target, mid + 1, high);
		else
			return binarysearch_aux(arr, target, low, mid);
	}
}