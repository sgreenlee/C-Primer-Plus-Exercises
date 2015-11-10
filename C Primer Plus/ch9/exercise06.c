// C Primer Plus
// Chapter 9 Exercise 6:

// Write and test a function that takes the addresses of three double variables
// as arguments and that moves the value of the smallest variable into the
// first variable, the middle value to the second variable, and the largest
// value into the third variable.

#include <stdio.h>

void sort_variables(double *x, double *y, double *z);

int main(void)
{
	double x, y, z;

	printf("Test sort_variables():\n");
	printf("Enter three numbers x, y and z:\n");
	while(scanf("%lf %lf %lf", &x, &y, &z) == 3)
	{
		putchar('\n');
		printf("Before calling sort_variables:\n");
		printf("x = %f, y = %f, z = %f\n", x, y, z);

		sort_variables(&x, &y, &z);

		putchar('\n');
		printf("After calling sort_variables:\n");
		printf("x = %f, y = %f, z = %f\n", x, y, z);

		putchar('\n');

		printf("Enter three numbers x, y and z:\n");
	}

	return 0;
}

void sort_variables(double *x, double *y, double *z)
{
	double tmp;

	if (*x > *y)
	{
		// switch x and y
		tmp = *y;
		*y = *x;
		*x = tmp;
	}

	if (*y > *z)
	{
		// switch y and z
		tmp = *z;
		*z = *y;
		*y = tmp;

		if (*x > *y)
		{
			// switch x and y
			tmp = *y;
			*y = *x;
			*x = tmp;
		}
	}
}
