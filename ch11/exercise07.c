// C Primer Plus
// Chapter 11 Exercise 7:

// The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1,
// truncating s2 or padding it with extra null characters as necessary. The
// target string may not be null-terminated if the length of s2 is n or more.
// The function returns s1. Write your own version of this function; call it
// mystrncpy(). Test the function in a complete program that uses a loop to
// provide input values for feeding to the function.

#include <stdio.h>

#define LIMIT 50

char * mystrcpy(char *s1, char *s2, int n);
char * get(char *string, int n);
void clear_string(char * string, int n);

int main(void)
{
	char s1[LIMIT];
	char s2[LIMIT];
	int n;

	printf("Enter a string to copy: ");
	get(s2, LIMIT);
	while (s2[0] != '\0')
	{
		printf("How many characters do you want to copy? (maximum %d) ", LIMIT);
		scanf("%d", &n);

		while (getchar() != '\n')
			continue;

		if (n > LIMIT)
			n = LIMIT;

		printf("Original string: %s\n", s2);
		mystrcpy(s1, s2, n);
		printf("Copy: %s\n", s1);

		clear_string(s1, LIMIT);

		printf("Enter a string to copy (empty line to quit): ");
		get(s2, LIMIT);
	}

	puts("Bye");

	return 0;
}

char * mystrcpy(char *s1, char *s2, int n)
{
	// copy n characters from s2 to s1
	// warning: if length of s2 is n or greater
	// then s1 may not be null terminated

	int i = 0;

	// copy n characters or until null char
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}

	// if i < n pad s1 with null character
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}

	return s1;
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

void clear_string(char *string, int n)
{
	// replace first n characters in string with nulls

	for (int i = 0; i < n; i++)
		string[i] = '\0';
}