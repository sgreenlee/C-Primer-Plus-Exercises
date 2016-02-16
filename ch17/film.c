// film.c -- implementation file for linked film list

#include "film.h"

// delete the entire film list and free allocated memory
void delete_list(List * list_ptr)
{

	Film * tmp, * list = *list_ptr;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}

	*list_ptr = NULL;
}

// add a film to the list;
void add_film(List filmlist, Film * new_film)
{
	Film * film_ptr = filmlist;
	while (film_ptr->next != NULL)
		film_ptr = film_ptr->next;
	film_ptr->next = new_film;
}

// print the list of films in original order
void list_films(List film_ptr)
{
	while (film_ptr != NULL)
	{
		printf("%s: %d\n", film_ptr->title, film_ptr->rating);
		film_ptr = film_ptr->next;
	}
}

// print the list of films in reverse order
void reverse_list_films(List film_ptr)
{
	if (film_ptr == NULL)
		return;
	else
	{
		reverse_list_films(film_ptr->next);
		printf("%s: %d\n", film_ptr->title, film_ptr->rating);
	}
}