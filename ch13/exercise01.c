// C Primer Plus
// Chapter 13 Exercise 1:

// Modify Listing 13.1 so that it solicits the user to enter the filename and
// reads the user’s response instead of using command-line arguments.

#include <stdio.h>
#include <stdlib.h>

#define SLEN 81

void get(char * string, int n);

int main(void)
{
	int ch;
	FILE * fp;
	char filename[SLEN];
	unsigned long chcount = 0;

	printf("Enter a file name: ");
	get(filename, SLEN);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Could not open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		chcount++;
	}

	printf("File %s has %lu characters.\n", filename, chcount);

	fclose(fp);

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