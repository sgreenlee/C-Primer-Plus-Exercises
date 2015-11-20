/* C Primer Plus

Chapter 3 Exercise 2:

Write a program that asks you to enter an ASCII code value, such as 66, and
then prints the character having that ASCII code. */


#include <stdio.h>
int main(void) 
{
	int ascii_code;
	printf("Enter an ASCII code: ");
	scanf("%d", &ascii_code);
	printf("Character for ASCII code %d: %c\n", ascii_code, ascii_code);

	return 0;
}
