// C Primer Plus
// Chapter 6 Exercise 7:
// Write a program that reads a single word into a character array and then prints
// the word backward. Hint: Use strlen() (Chapter 4) to compute the index of the
// last character in the array.

#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[30];

	printf("Enter a string: ");
	scanf("%s", word);
	for (int i = strlen(word) - 1; i >= 0; i--)
	{
		printf("%c", word[i]);
	}
	printf("\n");

	return 0;
}
