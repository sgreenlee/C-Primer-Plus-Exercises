// C Primer Plus
// Chapter 11 Exercise 11:

// Write a program that reads in up to 10 strings or to EOF, whichever comes
// first. Have it offer the user a menu with five choices: print the original
// list of strings, print the strings in ASCII collating sequence, print the
// strings in order of increasing length, print the strings in order of the
// length of the first word in the string, and quit. Have the menu recycle
// until the user enters the quit request. The program, of course, should
// actually perform the promised tasks.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define COUNT 10
#define LIMIT 50

void sort_ASCII(char *strings[], int n);
void sort_length(char *strings[], int n);
int fwlen(char *string);
void sort_firstword_length(char *strings[], int n);
char * get(char *string, int n);
void print_menu(void);

int main (void)
{
	char strings[COUNT][LIMIT];
	char *strptrs[COUNT];
	char * success;
	char ch;

	// initialize array of pointers
	for (int i = 0; i < COUNT; i++)
		strptrs[i] = strings[i];

	printf("Enter up to 10 strings (EOF to stop): \n");

	// read up to ten strings from input
	for (int i = 0; i < COUNT; i++)
	{
		printf("%d: ", i + 1);
		success = get(strings[i], LIMIT);

		// if EOF encountered, stop reading strings
		if (!success)
			break;
	}

	printf("\n");

	print_menu();
	while ((ch = getchar()) != 'q')
	{
		// discard rest of the line
		if (ch != '\n')
			while (getchar() != '\n')
				continue;

		// sort strings
		switch (ch)
		{
			case ('a'):
				sort_ASCII(strptrs, COUNT);
				break;
			case ('l'):
				sort_length(strptrs, COUNT);
				break;
			case ('f'):
				sort_firstword_length(strptrs, COUNT);
				break;
			case ('o'):
				break;
			default:
				printf("Invalid input. Try again.\n\n");
				print_menu();
				continue;
		}

		// print sorted strings
		puts("");
		for (int i = 0; i < COUNT; i++)
			puts(strptrs[i]);

		puts("");
		print_menu();
	}

	puts("Bye");
	return 0;
}

void sort_ASCII(char *strings[], int n)
{
	// sort array of string pointers by ASCII collating sequence

	char *tmp;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(strings[i], strings[j]) > 0)
			{
				tmp = strings[i];
				strings[i] = strings[j];
				strings[j] = tmp;
			}
		}
}

void sort_length(char *strings[], int n)
{
	// sort array of string pointers by length

	char *tmp;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (strlen(strings[i]) > strlen(strings[j]))
			{
				tmp = strings[i];
				strings[i] = strings[j];
				strings[j] = tmp;
			}
		}
}

int fwlen(char *string)
{
	// return length of first word of string

	int length = 0;

	// skip leading whitespace
	while (isspace(*string))
		string++;

	// count first word length
	while(!isspace(*string))
	{
		length++;
		string++;
	}

	return length;
}

void sort_firstword_length(char *strings[], int n)
{
	// sort array of string pointers by ASCII collating sequence

	char *tmp;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (fwlen(strings[i]) > fwlen(strings[j]))
			{
				tmp = strings[i];
				strings[i] = strings[j];
				strings[j] = tmp;
			}
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

void print_menu(void)
{
	puts("Choose an option:");
	puts("(o) Print strings in original order.");
	puts("(a) Print strings in ASCII collating sequence.");
	puts("(l) Print strings ordered by length.");
	puts("(f) Print strings ordered by length of the first word.");
	puts("(q) Quit.");
	puts("");
	puts("Enter a character: ");
}
