// C Primer Plus
// Chapter 6 Exercise 17:

// Chuckie Lucky won a million dollars (after taxes), which he places in an
// account that earns 8% a year. On the last day of each year, Chuckie
// withdraws $100,000. Write a program that finds out how many years it takes
// for Chuckie to empty his account.

#include <stdio.h>

int main(void)
{
	const float WINNINGS = 1000000.0f;
	const float INTEREST = 0.08f;
	const float SPENDING = 100000.0f;

	int years = 0;
	float balance = WINNINGS;

	// the problem is not quite clear, but I'm assuming
	// Chuckie makes his first withdrawal before collecting
	// any interest
	while (balance > 0)
	{
		balance -= SPENDING;
		balance *= 1.0f + INTEREST;
		years++;
	}

	printf("After %d years, Chuckie is in the red with a balance of"
		   " %.2f USD.\n", years, balance);

	return 0;
}
