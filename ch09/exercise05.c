// C Primer Plus:
// Chapter 9 Exercise 5:

// Write and test a function called larger_of() that replaces the contents of
// two double variables with the maximum of the two values. For example,
// larger_of(x,y) would reset both x and y to the larger of the two.

#include <stdio.h>

void larger_of(double * x, double * y);

int main(void)
{
	double x, y;

	printf("Test larger_of() function\n");
	printf("=========================\n");
	printf("Enter two numbers x and y: ");
	while(scanf("%lf %lf", &x, &y) == 2)
	{
		printf("Before calling larger_of():\n");
		printf("x = %f, y = %f\n", x, y);

		larger_of(&x, &y);

		printf("After calling larger_of():\n");
		printf("x = %f, y = %f\n", x, y);	

		printf("Enter two numbers x and y: ");
	}

	return 0;
}

void larger_of(double * x, double * y)
{
	// replace contents of 
	if (*x > *y) *y = *x;
	else *x = *y;
}