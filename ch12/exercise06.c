// C Primer Plus
// Chapter 12 Exercise 6:

// Write a program that generates 1,000 random numbers in the range 1–10. Don’t
// save or print the numbers, but do print how many times each number was
// produced. Have the program do this for 10 different seed values. Do the
// numbers appear in equal amounts? You can use the functions from this chapter
// or the ANSI C rand() and srand() functions, which follow the same format
// that our functions do. This is one way to examine the randomness of a
// particular random-number generator.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000


void random_sample(void);

int main(void)
{
	for (int i = 1; i < 11; i++)
	{
		printf("Random Sample: run #%d\n", i);
		srand(i);
		random_sample();
		putchar('\n');
	}

	return 0;
}

void random_sample(void)
{
	int counts[10] = {0,0,0,0,0,0,0,0,0,0};
	const int RAND_LIMIT = (RAND_MAX / 10) * 10;
	int rand_int;

	int i = 0;
	while (i < SIZE)
	{
		rand_int = rand();
		if (rand_int >= RAND_LIMIT)
			continue;
		else
		{
			rand_int %= 10;
			counts[rand_int]++;
		}
		i++;
	}
	puts("Counts");
	for (int i = 0; i < 10; i++)
		printf("%2d: %3d  ", i + 1, counts[i]);
	putchar('\n');

}