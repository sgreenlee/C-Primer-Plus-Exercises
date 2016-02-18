// C Primer Plus
// Chapter 17 Exercise 5:

// Write a program that lets you input a string. The program then should push
// the characters of the string onto a stack, one by one (see review question
// 5), and then pop the characters from the stack and display them. This
// results in displaying the string in reverse order.

#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return 1;
	}

	Stack character_stack;
	Stack * stack_ptr = InitializeStack(&character_stack);

	// for (char * pchar = argv[1]; *pchar != '\0'; pchar++)
	// 	printf("%c", *pchar);

	for (char * pchar = argv[1]; *pchar != '\0'; pchar++)
		PushItem(pchar, stack_ptr);

	char pch[1];
	while (PopItem(pch, stack_ptr))
		printf("%c", *pch);

	puts("");

}