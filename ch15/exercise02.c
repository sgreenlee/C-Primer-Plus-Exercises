// C Primer Plus
// Chapter 15 Exercise 2:

// Write a program that reads two binary strings as command-line arguments and
// prints the results of applying the ~ operator to each number and the results
// of applying the &, |, and ^ operators to the pair. Show the results as
// binary strings. (If you don’t have a command-line environment available,
// have the program read the strings interactively.)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int parsebinarystring(const char * string);
char * tobinarystring(int n, char * string, int strlen);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <arg1> <arg2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int n = parsebinarystring(argv[1]);
	int m = parsebinarystring(argv[2]);
	int strlen = sizeof(int) * CHAR_BIT + 1;
	char binstring[strlen];

	printf("~%s = %s\n", argv[1], tobinarystring(~n, binstring, strlen));
	printf("~%s = %s\n", argv[2], tobinarystring(~m, binstring, strlen));
	printf("%s & %s = %s\n", argv[1], argv[2], tobinarystring(n & m, binstring, strlen));
	printf("%s | %s = %s\n", argv[1], argv[2], tobinarystring(n | m, binstring, strlen));
	printf("%s ^ %s = %s\n", argv[1], argv[2], tobinarystring(n ^ m, binstring, strlen));

	return 0;
}

int parsebinarystring(const char * string)
{
	// convert a binary string to a numeric value

	int retval = 0;
	while (*string != '\0')
	{
		retval <<= 1;
		if (*string != '0' && *string != '1')
		{
			// handle input error
			fprintf(stderr, "Error: input string is not binary.\n");
			return 0;
		}
		if (*string == '1')
			retval |= 1;
		string++;
	}
	return retval;
}

char * tobinarystring(int n, char * string, int strlen)
{
	char * start = string;

	string += (strlen - 1);
	*string = '\0';
	string--;

	if (n == 0)
	{
		*string = '0';
		return string;
	}

	while (n != 0 && string >= start)
	{
		*string = (n & 1) + '0';
		n = n >> 1;
		string--;
	}
	return ++string;
}