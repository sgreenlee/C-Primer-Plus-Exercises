// C Primer Plus
// Chapter 11 Exercise 16:

// Write a program that reads input until end-of-file and echoes it to the
// display. Have the program recognize and implement the following command-line
// arguments:
// 	- p Print input as is
// 	- u Map input to all uppercase
// 	- l Map input to all lowercase
// Also, if there are no command-line arguments, let the program behave as if
// the –p argument had been used.

#include <stdio.h>
#include <ctype.h>

void map_identity(void);
void map_uppercase(void);
void map_lowercase(void);

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		map_identity();
		return 0;
	}

	else if (argc > 2 || (argc == 2 && argv[1][0] != '-'))
	{
		printf("Usage: program_name [-p | -l | -u]\n");
		return 1;
	}

	else
		switch(argv[1][1])
		{
			case ('p'):
				map_identity();
				break;
			case ('u'):
				map_uppercase();
				break;
			case ('l'):
				map_lowercase();
				break;
			default:
				printf("Usage: program_name [-p | -l | -u]\n");
				return 1;
		}

	return 0;
}

void map_identity(void)
{
	char ch;

	while((ch = getchar()) != EOF)
		putchar(ch);
}

void map_uppercase(void)
{
	char ch;

	while((ch = getchar()) != EOF)
	{
		if (islower(ch))
			ch = toupper(ch);
		putchar(ch);
	}
}

void map_lowercase(void)
{
	char ch;

	while((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			ch = tolower(ch);
		putchar(ch);
	}
}
