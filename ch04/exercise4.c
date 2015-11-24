/* C Primer Plus

Chapter 4 Exercise 4:

Write a program that requests your height in inches and your name, and then
displays the information in the following form:

    Dabney, you are 6.208 feet tall

Use type float, and use / for division. If you prefer, request the height in
centimeters and display it in meters. */

#include <stdio.h>

int main(void)
{
	const float INCHES_PER_FEET = 12;
	float height;
	char name[40];

	printf("What is your name?: ");
	scanf("%s", name);
	printf("What is your height in inches?: ");
	scanf("%f", &height);
	printf("%s, you are %.3f feet tall.\n", name, height / INCHES_PER_FEET);

	return 0;
}
