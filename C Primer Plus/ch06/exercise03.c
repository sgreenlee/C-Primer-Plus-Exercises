// C Primer Plus

// Chapter 6 Exercise 3:

// Use nested loops to produce the following pattern:
// F
// FE
// FED
// FEDC
// FEDCB
// FEDCBA

#include <stdio.h>

int main(void)
{
	for (int i = 1; i < 7; i++)
	{
		for (char c = 'F'; 'F' - c < i; c--)
		{
			printf("%c", c);
		}
		printf("\n");
	}

	return 0;
}
