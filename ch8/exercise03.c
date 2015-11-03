// C Primer Plus
// Chapter 8 Exercise 3:

// Write a program that reads input as a stream of characters until
// encountering EOF. Have it report the number of uppercase letters, the number
// of lowercase letters, and the number of other characters in the input. You
// may assume that the numeric values for the lowercase letters are sequential
// and assume the same for uppercase. Or, more portably, you can use
// appropriate classification functions from the ctype.h library.

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int uppercase_count = 0, lowercase_count = 0, other_count = 0;

	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			uppercase_count++;
		else if (islower(ch))
			lowercase_count++;
		else
			other_count++;
	}

	printf("Character Counts\n");
	printf("Uppercase letters: %d\n", uppercase_count);
	printf("Lowercase letters: %d\n", lowercase_count);
	printf("Other: %d\n", other_count);

	return 0;
}