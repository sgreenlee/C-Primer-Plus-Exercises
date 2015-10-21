/* C Primer Plus

Chapter 4 Exercise 1:

Write a program that asks for your first name, your last name, and then prints the names
in the format last, first. */

#include <stdio.h>

int main(void)
{
	char first_name[20];
	char last_name[20];

	printf("Enter your first and last name (e.g.: John Doe): ");
	scanf("%s %s", first_name, last_name);
	printf("%s, %s\n", last_name, first_name);

	return 0;
}
