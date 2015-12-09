// exercise07-b.c -- function definitions for exercise07.c

#include "exercise07.h"
#include <stdio.h>
#include <stdlib.h>

static int rolldie(int sides)
{
	// roll one n-sided die and return outcome

	return rand() % sides + 1;
}

int rolldice(int dice, int sides)
{
	// roll multiple n-sided dice and return outcome

	int total = 0;

	for (int i = 0; i < dice; i++)
		total += rolldie(sides);

	return total;
}

void dicerolls(int sets, int dice, int sides)
{
	// roll multiple sets of multiple n-sided dice and print results

	printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
	for (int i = 0; i < sets; i++)
		printf("%2d ", rolldice(dice, sides));
	putchar('\n');
}