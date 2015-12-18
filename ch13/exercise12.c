// C Primer Plus
// Chapter 13 Exercise 12:

// Create a text file consisting of 20 rows of 30 integers. The integers should
// be in the range 0–9 and be separated by spaces. The file is a digital
// representation of a picture, with the values 0 through 9 representing
// increasing levels of darkness. Write a program that reads the contents of
// the file into a 20-by-30 array of ints. In a crude approach toward
// converting this digital representation to a picture, have the program use
// the values in this array to initialize a 20-by-31 array of chars, with a 0
// value corresponding to a space character, a 1 value to the period character,
// and so on, with each larger number represented by a character that occupies
// more space. For example, you might use # to represent 9. The last character
// (the 31st) in each row should be a null character, making it an array of 20
// strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file.

// Note: use data.txt as input file to test this program.

#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

int main(int argc, char *argv[])
{
	FILE *fp;
	int data[ROWS][COLS];
	char img[ROWS][COLS + 1];
	char ch;

	if (argc != 3)
	{
		printf("Usage: %s <data file> <image file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// open data file
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// read ints from file
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			if (fscanf(fp, "%d", *(data + i) + j) != 1)
			{
				fprintf(stderr, "Invalid or corrupted data file.\n");
				exit(EXIT_FAILURE);
			}
	fclose(fp); // done with fp for now

	// convert ints to characters
	for (int i = 0; i < ROWS; i++)
	{	
		int j;
		for (j = 0; j < COLS; j++)
		{
			switch (data[i][j])
			{
				case(0):
					ch = ' ';
					break;
				case(1):
					ch = '.';
					break;
				case(2):
					ch = '\'';
					break;
				case(3):
					ch = ':';
					break;
				case(4):
					ch = '~';
					break;
				case(5):
					ch = '*';
					break;
				case(6):
					ch = '=';
					break;
				case(7):
					ch = '}';
					break;
				case(8):
					ch = '&';
					break;
				case(9):
					ch = '#';
					break;
				default:
					fprintf(stderr, "Error: int out of bounds.\n");
					exit(EXIT_FAILURE);
			}
			img[i][j] = ch;
		}
		img[i][j] = '\0'; // j = COLS here
	}

	// open image file
	if ((fp = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ROWS; i++)
	{
		// print to console and file
		puts(img[i]);
		fprintf(fp, "%s\n", img[i]);
	}
	fclose(fp);

	return 0;
}