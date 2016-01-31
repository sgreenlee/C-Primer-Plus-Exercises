// C Primer Plus
// Chapter 13 Exercise 8

// Write a program that takes as command-line arguments a character and zero or
// more filenames. If no arguments follow the character, have the program read
// the standard input. Otherwise, have it open each file in turn and report how
// many times the character appears in each file. The filename and the
// character itself should be reported along with the count. Include error-
// checking to see whether the number of arguments is correct and whether the
// files can be opened. If a file can’t be opened, have the program report that
// fact and go on to the next file.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char character;
	int ch;

	if (argc < 2)
	{
		printf("Usage: %s <char> [file1] [file2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	character = *(argv[1]);

	if (argc == 2)
	{
		int count = 0;

		// read from stdin
		while ((ch == getchar()) != EOF)
			if (ch == character)
				count++;

		printf("Character count for %c in ...\n", character);
		printf("Standard in: %d\n", count);
	}
	else
	{
		FILE * fp;
		int counts[argc - 2];
		for (int i = 2; i < argc; i++)
		{
			counts[i - 2] = 0;
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open file %s\n", argv[i]);
				continue;
			}

			while ((ch = getc(fp)) != EOF)
				if (ch == character)
					counts[i-2]++;

			fclose(fp);
		}

		printf("Character count for %c in ...\n", character);
		for (int i = 2; i < argc; i++)
			printf("%s: \t\t%d\n", argv[i], counts[i-2]);

	}

	return 0;
}
