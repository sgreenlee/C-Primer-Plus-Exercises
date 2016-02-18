// stack.c -- implementation file for stack type

#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

Stack * InitializeStack(Stack * pstack)
{
	*pstack = NULL;
	return pstack;
}

bool PushItem(const char * pch, Stack * pstack)
{
	Node * pnode = (Node *) malloc(sizeof(Node));
	if (pnode == NULL)
	{
		fprintf(stderr, "Stack is full. Could not add item.\n");
		return false;
	}
	else
	{
		pnode->item = *pch;
		pnode->previous = *pstack;
		*pstack = pnode;
		return true;
	}
}

bool PopItem(char * pch, Stack * pstack)
{
	if (*pstack == NULL)
		return false;
	else
	{
		*pch = (*pstack)->item;
		Node * tmp = *pstack;
		*pstack = (*pstack)->previous;
		free(tmp);
		return true;
	}
}

void EmptyStack(Stack * pstack)
{
	Node * tmp, * pnode = *pstack;
	while (pnode != NULL)
	{
		tmp = pnode->previous;
		free(pnode);
		pnode = tmp;
	}
}