// C Primer Plus
// Chapter 12 Exercise 4:

// Write and test in a loop a function that returns the number of times it has
// been called.

#include <stdio.h>

unsigned int counter(void);

int main(void)
{
	// test counter()
	int iterations = 0;
	printf("How many times do you want to call counter()? ");
	scanf("%d", &iterations);
	for (int i = 0; i < iterations; i++)
		printf("counter() returns %u\n", counter());

	return 0;
}

unsigned int counter(void)
{
	static unsigned int call_count = 0;
	return ++call_count;
}