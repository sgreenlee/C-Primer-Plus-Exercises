// C Primer Plus
// Chapter 7 Exercise 1:

// Write a program that reads input until encountering the # character and then
// reports the number of spaces read, the number of newline characters read,
// and the number of all other characters read.

#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	unsigned int spaces = 0, newlines = 0, other= 0;
	printf("Enter input (%c to stop):\n", STOP);
	while((ch = getchar()) != STOP)
	{
		if (ch == ' ')
			spaces++;
		else if (ch == '\n')
			newlines++;
		else
			other++;
	}
	printf("\n");
	printf("Character Count:\n");
	printf("----------------\n");
	printf("Spaces: %u\n"
		   "Newlines: %u\n"
		   "Other: %u\n", spaces, newlines, other);

	return 0;
}
