// C Primer Plus
// Chapter 13 Exercise 6:

// Programs using command-line arguments rely on the user’s memory of how to
// use them correctly. Rewrite the program in Listing 13.2 so that, instead of
// using command-line arguments, it prompts the user for the required
// information.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81

void get(char * string, int n);

int main(void)
{
	FILE *in;
	FILE *out;
	char source[SLEN];
	char dest[SLEN];
	int ch;
	unsigned int count = 0;

	printf("Enter a file to reduce: ");
	get(source, SLEN - 5);

	if ((in = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", source);
		exit(EXIT_FAILURE);
	}

	strcpy(dest, source);
	strcat(dest, ".red");
	if ((out = fopen(dest, "w")) == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", dest);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0)
		printf("Error in closing file %s.\n", source);
	if (fclose(out) != 0)
		printf("Error in closing file %s.\n", dest);

	return 0;
}

void get(char * string, int n)
{
	// wrapper for fgets - read from stdin and replace
	// first newline with null character

	fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}
		string++;
	}
}