// C Primer Plus
// Chapter 11 Exercise 3:

// Design and test a function that reads the first word from a line of input
// into an array and discards the rest of the line. It should skip over leading
// whitespace. Define a word as a sequence of characters with no blanks, tabs,
// or newlines in it. 

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 20

char * getword(char *target);

int main(void)
{
	// test getword()

	char hello[SIZE] = "Hello, ";

	printf("What's your name?");
	getword(hello + 7);
	puts(hello);

	return 0;
}

char * getword(char *target)
{
	// read input into character array target
	// stop after first word or EOF
	// discard rest of the line

	char ch;
	int i = 0;
	bool inword = false;

	while ((ch = getchar()) != EOF)
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