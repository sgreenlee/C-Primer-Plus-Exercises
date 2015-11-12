// C Primer Plus
// Chapter 9 Exercise 8

// Redo Programming Exercise 8, but this time use a recursive function.

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
	double dbl_power;

	// handle powers of zero
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

	if (exponent == 0) return 1; // stop recursion

	dbl_power = base * power(base, abs(exponent) - 1); // recursion step

	// if exponent is negative, take reciprocal
	if (exponent < 0) dbl_power = 1 / dbl_power;

	return dbl_power;
}