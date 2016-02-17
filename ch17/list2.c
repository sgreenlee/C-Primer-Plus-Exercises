/* list.c -- functions supporting list operations */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/* interface functions */

/* set the list to empty */
void InitializeList(List * plist)
{
	plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist) 
{
	return (plist->items == 0);
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
	return (plist->items == MAXSIZE);
}

/* returns number of items */
unsigned int ListItemCount(const List * plist) 
{
	return plist->items;
}

/* adds item to list */
bool AddItem(Item item, List * plist)
{
	if (plist->items < MAXSIZE)
	{
		plist->entries[plist->items] = item;
		(plist->items)++;
		return true;
	}
	else
		return false;
}

/* traverses the list, calling *pfun on every item */
void Traverse (const List * plist, void (* pfun)(Item item) ) 
{
	for (int i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]);
}

/* empty the list */
void EmptyTheList(List * plist)
{
	plist->items=0;
}
