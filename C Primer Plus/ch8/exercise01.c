// C Primer Plus
// Chapter 8 Exercise 1:

// Devise a program that counts the number of characters in its input up to the
// end of file.

#include <stdio.h>

int main(void)
{
	int count = 0;

	while (getchar() != EOF)
	{
		count++;
	}
	printf("Character count: %d\n", count);

	return 0;
}