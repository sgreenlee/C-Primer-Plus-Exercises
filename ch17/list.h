/* list.h -- header file for a simple list type */
#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h> 
#define TSIZE 45 /* size of array to hold title */

struct film
{
	char title[TSIZE];
	int rating;
};

/* general type definitions */
typedef struct film Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef struct list {
	Node * head;
	Node * end;
} List;

/* function prototypes */


// operation: initialize a list 								
// preconditions: plist points to a list 						
// postcondition: the list is initialized to empty 			
void InitializeList(List * plist);


// operation: determine if list is empty 						
// preconditions: plist points to an initialized list 			
// postcondition: function returns true if list is empty 		
// 				   and false otherwise							
bool ListIsEmpty(const List *plist);


// operation: determine if list is full
// preconditions: plist points to an initialized list
// postcondition: function returns true if list is full and false
// 				otherwise
bool ListIsFull(const List *plist);


// operation: determine number of items in list
// preconditions: plist points to an initialized list
// postconditions: function returns number of items in list
unsigned int ListItemCount(const List *plist);


// operation: add item to end of list
// preconditions: item is an item to be added to list
//				  plist points to an initialized list
// postcondition: if possible, function adds item to end
//				   of list and returns True; otherwise the
//				   function returns False
bool AddItem(Item item, List * plist);


// operation: apply a function to each item in list 
// preconditions: plist points to an initialized list
//			  	  pfun points to a function that takes an
//			 	  Item argument and has no return value
// postcondition: the function pointed to by pfun is
//				  executed once for each item in the list
void Traverse (const List *plist, void (* pfun)(Item item) );

// operation: free allocated memory, if any
// preconditions: plist points to an initialized list
// postcondition: any memory allocated for the list is freed
// 				  and the list is set to empty
void EmptyTheList(List * plist);

#endif