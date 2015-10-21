/* C Primer Plus

Chapter 3 Exercise 4:

Write a program that reads in a floating-point number and prints it first in decimal-point notation,
then in exponential notation, and then, if your system supports it, p notation. Have the output use 
the following format (the actual number of digits displayed for the exponent depends on the system):

Enter a floating-point value: 64.25
fixed-point notation: 64.250000
exponential notation: 6.425000e+01
p notation: 0x1.01p+6 */

#include <stdio.h>
int main(void) 
{
	float flt_input;

	printf("Enter a floating-point value: ");
	scanf("%f", &flt_input);
	printf("Fixed-point notation: %f\n", flt_input);
	printf("Exponential notation: %e\n", flt_input);
	printf("P notation: %a\n", flt_input);

	return 0;
}
