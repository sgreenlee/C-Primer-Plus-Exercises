// C Primer Plus

// Chapter 6 Exercise 2:

// Use nested loops to produce the following pattern:
// $
// $$
// $$$
// $$$$
// $$$$$

#include <stdio.h>

int main(void)
{
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("$");
		}
		printf("\n");
	}

	return 0;
}
