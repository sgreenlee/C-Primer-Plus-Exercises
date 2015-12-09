// C Primer Plus
// Chapter 12 Exercise 7:

// Write a program that behaves like the modification of Listing 12.13, which
// we discussed after showing the output of Listing 12.13. That is, have the
// program produce output like the following:
//     > Enter the number of sets; enter q to stop: 18
//     > How many sides and how many dice? 6 3
//     > Here are 18 sets of 3 6-sided throws.
//     > 12 10  6  9  8 14  8 15  9 14 12 17 11  7 10
//       13  8 14
//     > How many sets? Enter q to stop: q

// compile with exercise07-b.c

#include <stdio.h>
#include "exercise07.h"

void clear_input_stream(void);

int main(void)
{
	int sets, dice, sides;

	puts("Enter the number of sets; enter q to stop.");
	while (scanf("%d", &sets) == 1 && sets > 0)
	{
		dice = sides = -1;
		printf("How many sides and how many dice? ");
		scanf("%d %d", &sides, &dice);
		while (dice < 0 || sides < 0)
		{
			clear_input_stream();
			puts("Invalid input. Positive integers only.");
			puts("How many sides and how many dice? ");
			scanf("%d %d", &sides, &dice);
		}

		dicerolls(sets, dice, sides);

		puts("How many sets? Enter q to stop.");
	}

	return 0;
}

void clear_input_stream(void)
{
	while (getchar() != '\n')
		continue;
}
