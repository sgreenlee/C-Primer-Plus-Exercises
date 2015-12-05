// C Primer Plus
// Chapter 11 Exercise 9

// Write a function that replaces the contents of a string with the string
// reversed. Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.

#include <stdio.h>

#define LIMIT 50

void reverse_string(char *string);
char * get(char *string, int n);

int main(void)
{
	// test reverse_string()

	char string[LIMIT];

	printf("Enter a string to reverse: ");
	get(string, LIMIT);
	while (string[0] != '\0')
	{
		reverse_string(string);
		printf("Your string reversed: %s\n", string);

		printf("Enter a string to reverse (empty line to quit): ");
		get(string, LIMIT);
	}

	puts("Bye");
	return 0;
}

void reverse_string(char *start)
{
	// replace contents of a string with the string reversed

	char *end = start;
	char tmp;

	// find location of the end of the string
	while (*(end + 1) != '\0')
		end++;

	// switch characters
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
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
