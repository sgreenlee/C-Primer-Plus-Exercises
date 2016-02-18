#ifndef STACK_H_
#define STACK_H_ 1

// stack.h -- header file for a stack type

#include <stdbool.h>

// Type definitions

typedef struct node
{
	char item;
	struct node * previous;
} Node;

typedef Node * Stack;

// Operations

// Initialize a list
Stack * InitializeStack(Stack * pstack);

// Attempt to add char ch to the stack pointed to by pstack.
// Returns true if operation is successful, else false
bool PushItem(const char * pch, Stack * pstack);

// Pop item from stack and place in location pointed to by pch.
// Returns true if operation succeeds, false if stack is empty
bool PopItem(char *pch, Stack * pstack);

// Empty Stack and free memory
void EmptyStack(Stack * pstack);

#endif