// C Primer Plus
// Chapter 6 Exercise 12:

// Consider these two infinite series:
// 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
// 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
// Write a program that evaluates running totals of these two series up to some
// limit of number of terms. Hint: –1 times itself an odd number of times is –1,
// and –1 times itself an even number of times is 1. Have the user enter the limit
// interactively; let a zero or negative value terminate input. Look at the running
// totals after 100 terms, 1000 terms, 10,000 terms. Does either series appear to
// be converging to some value?

#include <stdio.h>

int main(void)
{
	long int limit;
	float sign = 1.0f;
	float series1 = 0, series2 = 0;

	printf("Enter a number of terms to sum: ");
	scanf("%ld", &limit);

	for (long int i = 1; i <= limit; i++)
	{
		series1 += 1.0f/i;
		series2 += (1.0f/i) * sign;
		sign = -sign; // toggle sign
	}

	printf("The %ldth partial sum for series 1 is: %.5f\n", limit, series1);
	printf("The %ldth partial sum for series 2 is: %.5f\n", limit, series2);

	// Answer: Series 1 has no limit. Series 2 appears to be bounded above

	return 0;
}
