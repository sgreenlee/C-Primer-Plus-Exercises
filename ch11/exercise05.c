// C Primer Plus
// Chapter 11 Exercise 5:

// Design and test a function that searches the string specified by the first
// function parameter for the first occurrence of a character specified by the
// second function parameter. Have the function return a pointer to the
// character if successful, and a null if the character is not found in the
// string. (This duplicates the way that the library strchr() function works.)
// Test the function in a complete program that uses a loop to provide input
// values for feeding to the function.

#include <stdio.h>

#define LIMIT 50

char * findchar(char *str, const char ch);

int main(void)
{
	char string[LIMIT];
	char *chloc;
	char ch;

	// test findchar()
	printf("Enter a string to search: ");
	fgets(string, LIMIT, stdin);
	while (string[0] != '\n')
	{
		printf("Enter a character to search for: ");
		ch = getchar();
		// discard rest of line if any
		if (ch != '\n')
			while (getchar() != '\n')
				continue;

		chloc = findchar(string, ch);
		if (chloc == NULL)
			printf("Character %c not found in %s", ch, string);
		else
			printf("Character %c found  at index %lu in %s", ch, chloc - string, string);

		// get new input
		printf("Enter a string to search (empty line to quit): ");
		fgets(string, LIMIT, stdin);
	}

	puts("Bye");

	return 0;
}

char * findchar(char *str, const char ch)
{
	// find and return pointer to first occurence of
	// char ch in string str. return NULL if not found

	while (*str != '\0')
	{
		if (*str == ch)
			return str;
		str++;
	}

	// if ch is not found, return null
	return NULL;
}
