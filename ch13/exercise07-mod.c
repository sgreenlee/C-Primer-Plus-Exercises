// C Primer Plus
// Chapter 13 Exercise 7:

// Write a program that opens two files. You can obtain the filenames either by
// using command-line arguments or by soliciting the user to enter them.
//   a. Have the program print line 1 of the first file, line 1 of the second
// 		file, line 2 of the first file, line 2 of the second file, and so on,
// 		until the last line of the longer file (in terms of lines) is printed.
//   b. Modify the program so that lines with the same line number are printed
// 		on the same line.

#include <stdio.h>
#include <stdlib.h>

#define LLEN 70 

void fget(char * string, int n, FILE *file);

int main(int argc, char *argv[])
{
	FILE *file1, *file2;
	int ch;
	char tmp[LLEN];

	if (argc < 3)
	{
		printf("Usage: %s file1 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((file1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((file2 = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		tmp[0] = '\0';
		fget(tmp, LLEN, file1);
		printf("%-*s\t", LLEN, tmp);

		tmp[0] = '\0';
		fget(tmp, LLEN, file2);
		printf("%-*s\n", LLEN, tmp);

		if (feof(file1) && feof(file2))
			break;
	}

	return 0;
}

void fget(char * string, int n, FILE *file)
{
	// wrapper for fgets - replaces
	// first newline with null character

	fgets(string, n, file);

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