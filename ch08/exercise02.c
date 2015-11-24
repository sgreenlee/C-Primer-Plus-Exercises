// C Primer Plus
// Chapter 8 Exercise 2:

// Write a program that reads input as a stream of characters until
// encountering EOF. Have the program print each input character and its ASCII
// decimal value. Note that characters preceding the space character in the
// ASCII sequence are nonprinting characters. Treat them specially. If the
// nonprinting character is a newline or tab, print \n or \t, respectively.
// Otherwise, use control-character notation. For instance, ASCII 1 is Ctrl+A,
// which can be displayed as ^A. Note that the ASCII value for A is the value
// for Ctrl+A plus 64. A similar relation holds for the other nonprinting
// characters. Print 10 pairs per line, except start a fresh line each time a
// newline character is encountered. (Note: The operating system may have
// special interpretations for some control characters and keep them from
// reaching the program.)

#include <stdio.h>

int main(void)
{
	int ch, char_count = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= ' ')
			printf("\'%c\': %d", ch, ch);
		else if (ch == '\n')
			printf("\'\\n\': %d", ch);
		else if (ch == '\t')
			printf("\'\\t\': %d", ch);
		else // ascii control characters
			printf("\'^%c\': %d", ch + 64, ch );

		char_count++;
		if (char_count % 10 == 0)
			printf("\n"); // print new line for every 10 characters
		else
			printf("  "); // otherwise, print spaces
	}

	printf("\n");

	return 0;
}