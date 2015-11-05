// C Primer Plus
// Chapter 8 Exercise 6:

// Modify the get_first() function of Listing 8.8 so that it returns the first
// non- whitespace character encountered. Test it in a simple program.

#include <stdio.h>
#include <ctype.h>

int get_first(void);

int main(void)
{
	int ch;

	printf("Test program for get_first():\n");
	printf("Enter a line; you should see the first non-whitespace\n");
	printf("character echoed in the terminal:\n");

	ch = get_first();
	printf("%c\n", ch);

	return 0;
}

int get_first(void)
{
	// returns first non-whitespace character and clears
	// remaining input until next line break or EOF

	int ch, garbage;

	do {
		ch = getchar();
	}
	while (isspace(ch));
		

	while((garbage = getchar()) != '\n' && garbage != EOF)
		;

	return ch;
}