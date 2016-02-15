// C Primer Plus:
// Chapter 16 Exercise 6:

// Write a function that takes as arguments the name of an array of type int
// elements, the size of an array, and a value representing the number of
// picks. The function then should select the indicated number of items at
// random from the array and prints them. No array element is to be picked more
// than once. (This simulates picking lottery numbers or jury members.) Also,
// if your implementation has time() (discussed in Chapter 12) or a similar
// function available, use its output with srand() to initialize the rand()
// random- number generator. Write a simple program that tests the function.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_SIZE 100

void sample(int * arr, int arr_size, int n);

int main(void)
{
	// test sample()

	int array[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
		array[i] = i;

	int n;
	printf("How many items would you like to sample: ");
	while(scanf("%d", &n) == 1 && n > 0)
	{
		sample(array, ARR_SIZE, n);
		printf("How many items would you like to sample: ");
	}

	puts("Bye.");
}

void sample(int * arr, int arr_size, int n)
{
	// pick and print a sample of n items from arr at random

	if (n > arr_size)
	{
		printf("Error: sample size can not be larger than the size of the array being sampled.\n");
		return;
	} 
	
	bool chosen[arr_size];
	for (int i = 0; i < arr_size; i++)
		chosen[i] = false;
	
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		int index = rand() % arr_size;
		while (chosen[index]) // if index has already been chosen, pick again
			index = rand() % arr_size;
		printf("%d\n", arr[index]);
		chosen[index] = true;
	}
	return;
}