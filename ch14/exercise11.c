// C Primer Plus
// Chapter 14 Exercise 11:

// Write a function called transform() that takes four arguments: the name of a
// source array containing type double data, the name of a target array of type
// double, an int representing the number of array elements, and the name of a
// function (or, equivalently, a pointer to a function). The transform()
// function should apply the indicated function to each element in the source
// array, placing the return value in the target array. For example, the call
//     transform(source, target, 100, sin);
// would set target[0] to sin(source[0]), and so on, for 100 elements. Test the
// function in a program that calls transform() four times, using two functions
// from the math.h library and two suitable functions of your own devising as
// arguments to successive calls of the transform() function.

#include <stdio.h>
#include <math.h>

#define ARRLENGTH 20

void transform(const double * source, double * target, int n, double (*func)(double));
double squared(double);
double cubed(double);

int main(void)
{
	// test transform function 
	
	double source[ARRLENGTH];
	double target[ARRLENGTH];

	for (int i = 0; i < ARRLENGTH; i++)
		source[i] = i;

	transform(source, target, ARRLENGTH, sin);
	for (int i = 0; i < ARRLENGTH; i++)
	{
		printf("sin(%.2f) = %.2f\n", source[i], target[i]);
	}
	puts("");

	transform(source, target, ARRLENGTH, tan);
	for (int i = 0; i < ARRLENGTH; i++)
	{
		printf("tan(%.2f) = %.2f\n", source[i], target[i]);
	}
	puts("");

	transform(source, target, ARRLENGTH, squared);
	for (int i = 0; i < ARRLENGTH; i++)
	{
		printf("%.2f ^ 2 = %.2f\n", source[i], target[i]);
	}
	puts("");

	transform(source, target, ARRLENGTH, cubed);
	for (int i = 0; i < ARRLENGTH; i++)
	{
		printf("%.2f ^ 3 = %.2f\n", source[i], target[i]);
	}
	puts("");

	return 0;
}

void transform(const double * source, double * target, int n, double (*func)(double))
{
	for (int i = 0; i < n; i++)
		target[i] = func(source[i]);

	return;
}

double squared(double x)
{
	return x * x;
}

double cubed(double x)
{
	return x * x * x;
}