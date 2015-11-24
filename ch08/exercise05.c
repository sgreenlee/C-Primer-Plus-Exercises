// C Primer Plus
// Chapter 8 Exercise 05:

// Modify the guessing program of Listing 8.4 so that it uses a more
// intelligent guessing strategy. For example, have the program initially guess
// 50, and have it ask the user whether the guess is high, low, or correct. If,
// say, the guess is low, have the next guess be halfway between 50 and 100,
// that is, 75. If that guess is high, let the next guess be halfway between 75
// and 50, and so on. Using this binary search strategy, the program quickly
// zeros in on the correct answer, at least if the user does not cheat.

#include <stdio.h>

int main(void)
{
	// initial search parameters
	int upper_bound = 100;
	int lower_bound = 0;
	int guess = 50;

	char ch;

	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a y if my guess is right, with a h if it's");
	printf("\ntoo high and an l if it's too low.\n");
	printf("Uh...is your number %d?\n", guess);

	while ((ch = getchar()) != 'y')
	{
		while (getchar() != '\n') // clear input stream
			;
		if (ch == 'h')
			upper_bound = guess;
		else if (ch == 'l')
			lower_bound = guess;
		else
		{
			printf("Invalid valid input. Try again.\n");
			continue;
		}
		guess = (upper_bound + lower_bound) / 2.0;
		printf("Well, then, is it %d?\n", guess);
	}

	printf("I knew I could do it!\n");
	return 0;
}