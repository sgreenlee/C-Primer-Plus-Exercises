/* C Primer Plus

Chapter 4 Exercise 3:

Write a program that reads in a floating-point number and prints it first in
decimal-point notation and then in exponential notation. Have the output use
the following formats (the number of digits shown in the exponent may be
different for your system):

a. The input is 21.3 or 2.1e+001.
b. The input is +21.290 or 2.129E+001. */

#include <stdio.h>

int main(void)
{
	float num;

	printf("Enter a number: ");
	scanf("%f", &num);
	printf("The input is %.1f or %.1e\n", num, num);
	printf("The input is %+.3f or %.3E\n", num, num);

	return 0;
}
