// C Primer Plus
// Chapter 6 Exercise 13:

// Write a program that creates an eight-element array of ints and sets the
// elements to the first eight powers of 2 and then prints the values. Use a for
// loop to set the values, and, for variety, use a do while loop to display the
// values.

#include <stdio.h>

int main(void)
{
	int powers_of_2[8];
	int power = 1;
	int i;

	for (int i = 0; i < 8; i++)
	{
		power *= 2;
		powers_of_2[i] = power;
	}
	printf("Powers of 2:\n");
	i = 0;
	do {
		printf("%d ", powers_of_2[i]);
		i++;
	} while (i < 8);
	printf("\n");

	return 0;
}
