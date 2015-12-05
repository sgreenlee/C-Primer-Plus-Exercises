// C Primer Plus
// Chapter 11 Exercise 10:

// Write a function that takes a string as an argument and removes the spaces
// from the string. Test it in a program that uses a loop to read lines until
// you enter an empty line. The program should apply the function to each input
// string and display the result.

#include <stdio.h>

#define LIMIT 50

void remove_spaces(char *string);
char * get(char *string, int n);

int main(void)
{
	// test remove_spaces()

	char string[LIMIT];

	printf("Test remove_spaces()\n");

	printf("Enter a string: ");
	get(string, LIMIT);
	while (string[0] != '\0')
	{
		remove_spaces(string);
		printf("Your string, without spaces: %s\n", string);

		printf("Enter a string (empty line to quit): ");
		get(string, LIMIT);
	}
	puts("Bye");

	return 0;
}

void remove_spaces(char *string)
{
	// remove all spaces from a string

	unsigned long spaces_found = 0;

	while (1)
	{
		if (*string == ' ')
			spaces_found++;
		else
			*(string - spaces_found) = *string;

		// if end of string, break
		if (*string == '\0')
			break;

		string++;
	}
}

char * get(char *string, int n)
{
	// wrapper for fgets that replaces first newline with null

	char *return_value = fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}

		string++;
	}

	return return_value;
}
