/* C Primer Plus

Chapter3 Exercise 7:

There are 2.54 centimeters to the inch. Write a program that asks you to enter
your height in inches and then displays your height in centimeters. Or, if you
 prefer, ask for the height in centimeters and convert that to inches. */

#include <stdio.h>

int main(void)
{
	float CM_PER_INCH = 2.54;
	float height;

	printf("Enter your height (in inches): ");
	scanf("%f", &height);
	printf("You are %f centimeters tall.\n", height * CM_PER_INCH);

	return 0;
}
