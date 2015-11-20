/* C Primer Plus

Chapter 5 Exercise 2:

Write a program that asks for an integer and then prints all the integers from
(and including) that value up to (and including) a value larger by 10. (That
is, if the input is 5, the output runs from 5 to 15.) Be sure to separate each
output value by a space or tab or newline. */

#include <stdio.h>

int main(void)
{
	int input;
	int i = 0;

	printf("Enter an integer: ");
	scanf("%d", &input);
	while (i <= 10)
	{
		printf("%d\n", input + i);
		i++;
	}

	return 0;
}
