// C Primer Plus
// Chapter 13 Exercise 05:

// Modify the program in Listing 13.5 so that it uses a command-line interface
// instead of an interactive interface.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	FILE * fa;
	FILE * fs;
	int files = 0;
	int ch;

	if (argc < 3)
	{
		printf("Usage: %s targetfile sourcefile1 [sourcefile2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fa = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fprintf(stderr, "Could not create output buffer.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 2; i < argc; i++)
	{
		if (strcmp(argv[i], argv[1]) == 0)
		{
			fprintf(stderr, "Can't append file to itself.\n");
		}
		else if ((fs = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Could not open file %s\n", argv[i]);
		}
		else
		{ 
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fprintf(stderr, "Could not create input buffer.\n");
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in writing to file %s.\n", argv[1]);
			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
		}
	}
	printf("Done appending. %d files appended.\n", files);

	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Done displaying.\n");
	fclose(fa);

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}