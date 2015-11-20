/* C Primer Plus

Chapter 5 Exercise 1:

Write a program that converts time in minutes to time in hours and minutes. Use
#define or const to create a symbolic constant for 60. Use a while loop to
allow the user to enter values repeatedly and terminate the loop if a value for
the time of 0 or less is entered. */

#include <stdio.h>

const int MINUTES_PER_HOUR = 60;

int main(void)
{
	int minutes;

	printf("Enter an amount of time in minutes: "); // get first input
	scanf("%d", &minutes);
		
	while (minutes > 0)
	{
		printf("%d minute(s) is %d hour(s) and %d minute(s).\n",
			   minutes,
			   minutes / MINUTES_PER_HOUR, // hours
			   minutes % MINUTES_PER_HOUR); // minutes

		printf("Enter an amount of time in minutes: "); // get new input
		scanf("%d", &minutes);
	}

	return 0;
}
