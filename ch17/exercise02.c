// C Primer Plus
// Chapter 17 Exercise 2:

// Suppose list.h (Listing 17.3) uses the following definition of a list:
// 	typedef struct list {
// 		Node * head; /* points to head of list */
// 		Node * end; /* points to end of list */
// 	} List;
// Rewrite the list.c (Listing 17.5) functions to fit this definition and test
// the resulting code with the films3.c (Listing 17.4) program.

// Compile with list.c

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showmovies(Item item);
char * get(char * st, int n);
int main(void)
{
	List movies;
	Item temp;

	/* initialize */
	InitializeList(&movies);

	if (ListIsFull(&movies))
	{
		fprintf(stderr,"No memory available! Bye!\n");
		exit(1);
	}

	/* gather and store */
	puts("Enter first movie title:");
	while (get(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while(getchar() != '\n')
			continue;
		
		if (AddItem(temp, &movies)==false) 
		{
			fprintf(stderr,"Problem allocating memory\n");
			break;
		}

		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}

		puts("Enter next movie title (empty line to stop):"); 
	}
	
	/* display */
	if (ListIsEmpty(&movies))
		printf("No data entered. ");
	else
	{
		printf ("Here is the movie list:\n");
		Traverse(&movies, showmovies);
	}

	printf("You entered %d movies.\n", ListItemCount(&movies));

	/* clean up */
	EmptyTheList(&movies);

	printf("Bye!\n");
	return 0;
}

void showmovies(Item item)
{
	printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

char * get(char * string, int n)
{
	// wrapper for fgets that replaces first newline with null

	char *return_value = fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}
		string++;
	}

	return return_value;
}
