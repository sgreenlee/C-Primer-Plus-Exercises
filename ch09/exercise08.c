// C Primer Plus
// Chapter 9 Exercise 8

// Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
// function that returned the result of raising a type double number to a
// positive integer value. Improve the function so that it correctly handles
// negative powers. Also, build into the function that 0 to any power other
// than 0 is 0 and that any number to the 0 power is 1. (It should report that
// 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop. Test
// the function in a program.

#include <stdio.h>
#include <stdlib.h> // prototype for abs() 

double power(double base, int exponent);

int main(void)
{
	double base, output;
	int exponent;

	printf("Test power() function:\n");
	printf("Enter a :double: base and :int: exponent: ");
	while (scanf("%lf %d", &base, &exponent) == 2)
	{
		output = power(base, exponent);

		printf("%f ^ %d = %f \n", base, exponent, output);

		printf("Enter a :double: base and :int: exponent: ");
	}

	return 0;
}

double power(double base, int exponent)
{
	double power = base;

	if (base == 0)
	{
		if (exponent == 0)
		{
			printf("Warning: 0 ^ 0 is undefined. Using 1.\n");
			return 1.0;
		}
		else
			return 0;
	}

	for (int i = 1; i < abs(exponent); i++)
	{
		power *= base;
	}

	if (exponent < 0)
		power = 1 / power;

	return power;
}