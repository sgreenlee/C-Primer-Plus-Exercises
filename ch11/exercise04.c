// C Primer Plus
// Chapter 11 Exercise 4:

// Design and test a function like that described in Programming Exercise 3
// except that it accepts a second parameter specifying the maximum number of
// characters that can be read.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 20

char * getword(char *target, int max);

int main(void)
{
	// test getword()

	char hello[SIZE] = "Hello, ";
	int space = SIZE - strlen(hello) - 1;

	puts("What's your name?");
	getword(hello + 7, space);
	puts(hello);

	return 0;
}

char * getword(char *target, int max)
{
	// read input into character array target
	// stop after first word , EOF or max characters
	// discard rest of the line

	char ch;
	int i = 0;
	bool inword = false;

	while ((ch = getchar()) != EOF && i < max)
	{
		if (isspace(ch))
		{
			if (inword)
				break; // word is over, exit while loop
			else
			{
				continue; // skip leading whitespace
			}
		}

		// if ch is not whitespace
		if (!inword)
			inword = true;

		*(target + i) = ch;
		i++;
	}

	// discard rest of the line if any
	if (ch != '\n')
		while ((ch = getchar()) != '\n')
			continue;

	return target;
}