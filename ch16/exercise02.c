// C Primer Plus
// Chapter 16 Exercise 2:

// The harmonic mean of two numbers is obtained by taking the inverses of the
// two numbers, averaging them, and taking the inverse of the result. Use a
// #define directive to define a macro “function” that performs this operation.
// Write a simple program that tests the macro.

#include <stdio.h>
#include "exercise01.h"

#define INVERSE(X) (1. / (X))
#define HARM_MEAN(X, Y) (1. / ((INVERSE(X) + INVERSE(Y)) / 2))

int main()
{
	// test HARM_MEAN

	double x, y;
	printf("Enter two numbers: ");
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		CLEARINPUT;
		printf("The harmonic mean of %.3f and %.3f is: %.3f.\n", x, y,
			   HARM_MEAN(x, y));

		printf("Enter two numbers: ");
	}
	puts("Bye.");
}