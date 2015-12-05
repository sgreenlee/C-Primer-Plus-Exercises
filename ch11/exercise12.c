// C Primer Plus
// Chapter 11 Exercise 12:

// Write a program that reads input up to EOF and reports the number of words,
// the number of uppercase letters, the number of lowercase letters, the number
// of punctuation characters, and the number of digits. Use the ctype.h family
// of functions.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	// read input to EOF and report number of words, lowercase letters,
	// uppercase letters, punct. marks and digits

	char ch;
	int upcase_letters, lowcase_letters, punct_chars, digits, words;
	upcase_letters = lowcase_letters = punct_chars = digits = words = 0;
	bool inword = false;

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			if (!inword) // count new word
			{
				inword = true;
				words++;
			}

			if (isupper(ch))
				upcase_letters++;
			if (islower(ch))
				lowcase_letters++;
		}
		else if (ispunct(ch))
		{
			punct_chars++;

			if (ch != '-' && ch != '\'')
				inword = false;
		}
		else if (isdigit(ch))
		{
			digits++;
			inword = false;
		}
		else if (isspace(ch))
			inword = false;
	}

	printf("Number of %s: %d\n", "lowercase letters", lowcase_letters);
	printf("Number of %s: %d\n", "uppercase letters", upcase_letters);
	printf("Number of %s: %d\n", "punctuation characters", punct_chars);
	printf("Number of %s: %d\n", "digits", digits);
	printf("Number of %s: %d\n", "words", words);

	return 0;
}
