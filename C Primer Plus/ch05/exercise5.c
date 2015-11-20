/* C Primer Plus

Chapter 5 Exercise 5:

Change the program addemup.c (Listing 5.13), which found the sum of the first 20
integers. (If you prefer, you can think of addemup.c as a program that calculates
how much money you get in 20 days if you receive $1 the first day, $2 the second
day, $3 the third day, and so on.) Modify the program so that you can tell it
interactively how far the calculation should proceed. That is, replace the 20 with
a variable that is read in. */

#include <stdio.h>

int main(void)
{
	int count, sum, max_count;
	sum = 0;
	count = 1;

	printf("How many integers would you like to sum? ");
	scanf("%d", &max_count);
	while (count <= max_count)
	{
		sum = sum + count;
		count++;
	}
	printf("sum = %d\n", sum);

	return 0;
}
