// C Primer Plus
// Chapter 13 Exercise 2:

// Write a file-copy program that takes the original filename and the copy file
// from the command line. Use standard I/O and the binary mode, if possible.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ch;
	FILE * fsource;
	FILE * fdest;

	if (argc != 3)
	{
		printf("Usage: %s source_file destination_file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fsource = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Could not open file %s for read\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fdest = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Could not open file %s for write\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fsource)) != EOF)
		putc(ch, fdest);

	fclose(fsource);
	fclose(fdest);

	return 0;
}