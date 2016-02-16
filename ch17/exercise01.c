// C Primer Plus
// Chapter 17 Exercise 1:

// Modify Listing 17.2 so that it displays the movie list both in the original
// order and in reverse order. One approach is to modify the linked-list
// definition so that the list can be traversed in both directions. Another
// approach is to use recursion.

// compile with film.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"

char * get(char * string, int n);

int main(void)
{
	List film_list = NULL;
	Film * current;
	char input[TSIZE];

	puts("Enter first movie title:");
	while (get(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (Film *) malloc(sizeof(Film));
		if (current == NULL)
		{
			fprintf(stderr, "Could not allocate memory.\n");
			exit(EXIT_FAILURE);
		}

		current->next = NULL;
		strcpy(current->title, input);
		printf("Enter your rating (0 - 10): ");
		scanf("%d", &(current->rating));
		while (getchar() != '\n') continue;

		if (film_list == NULL)
			film_list = current;
		else
			add_film(film_list, current);

		puts("Enter next movie title (empty line to stop):");
	}

	// show list of movies
	puts("Here is your list of movies:");
	list_films(film_list);
	puts("");

	// show list of movies in reverse order
	puts("Here is your list of movies in reverse order:");
	reverse_list_films(film_list);

	// clean up
	delete_list(&film_list);

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
