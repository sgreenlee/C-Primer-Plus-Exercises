// C Primer Plus

// Chapter 5 Exercise 7:

// Write a program that requests a type double number and prints the value of the
// number cubed. Use a function of your own design to cube the value and print it.
// The main() program should pass the entered value to this function.

#include <stdio.h>

double cubed(double n); // prototype declaration for cubed

int main(void)
{
	double input;
	printf("Enter a number to cube: ");
	scanf("%lf", &input);

	printf("%.3f cubed is %.3f\n", input, cubed(input));

	return 0;
}

double cubed(double n)
{
	return n * n * n;
}
