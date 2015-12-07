// C Primer Plus
// Chapter 11 Exercise 13

// Write a program that echoes the command-line arguments in reverse word
// order. That is, if the command-line arguments are see you later, the program
// should print later you see.

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Error: at least one command-line argument required.\n");
		return 1;
	}
	else
		for (int i = argc - 1; i > 0; i--)
			printf("%s ", argv[i]);

	puts("");
	return 0;
}
