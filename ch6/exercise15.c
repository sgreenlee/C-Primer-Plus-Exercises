// C Primer Plus
// Chapter 6 Exercise 15:

// Write a program that reads in a line of input and then prints the line in
// reverse order. You can store the input in an array of char; assume that the
// line is no longer than 255 characters. Recall that you can use scanf() with
// the %c specifier to read a character at a time from input and that the newline
// character (\n) is generated when you press the Enter key.

#include <stdio.h>

int main(void)
{
	char line[255];
	int i = 0; // array index
	printf("Enter a line to reverse:\n");
	while (scanf("%c", &line[i]), line[i] != '\n')
		i++;

	for (; 0 <= i; i--) // previous loop leaves i in right position
		printf("%c", line[i]);

	printf("\n");

	return 0;
}
