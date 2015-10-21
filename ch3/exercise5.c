/* C Primer Plus

Chapter 3 Exercise 5

There are approximately 3.156 × 10^7 seconds in a year. Write a program that requests 
your age in years and then displays the equivalent number of seconds. */

#include <stdio.h>

int main(void)
{
	unsigned int SECONDS_PER_YEAR = 31560000;
	unsigned int age;

	printf("What is your age (in years)?: ");
	scanf("%u", &age);
	printf("You are %u seconds old!\n", SECONDS_PER_YEAR * age);

	return 0;
}
