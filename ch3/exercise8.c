/* C Primer Plus

Chapter 3 Exercise 8:

In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces,
an ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program
that requests a volume in cups and that displays the equivalent volumes in
pints, ounces, tablespoons, and teaspoons. Why does a floating-point type make
more sense for this application than an integer type? */

#include <stdio.h>

int main(void)
{

	/* If the number of cups is not an even whole number, then the number of
		pints will not be a whole number. */
	float PINTS_PER_CUP = .5;
	float OUNCES_PER_CUP = 8;
	float TBS_PER_CUP = 2 * OUNCES_PER_CUP; // tablespoons/ounce * ounces/cup
	float TSP_PER_CUP = 3 * TBS_PER_CUP; // teaspoons/tablespoon * tablespoons/ounce * ounces/cup
	float cups;

	printf("Enter an amount in cups:");
	scanf("%f", &cups);
	printf("%f cups is equivalent to:\n", cups);
	printf("%f pints\n", cups * PINTS_PER_CUP);
	printf("%f ounces\n", cups * OUNCES_PER_CUP);
	printf("%f tablespoons\n", cups * TBS_PER_CUP);
	printf("%f teaspoons\n", cups * TSP_PER_CUP);

	return 0;
}
