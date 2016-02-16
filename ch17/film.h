#ifndef FILM_H_
#define FILM_H_ 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TSIZE 45

typedef struct film 
{
	char title[TSIZE];
	int rating;
	struct film * next;
} Film;

typedef Film * List;

// delete the entire film list and free allocated memory
void delete_list(List * list);

// add a film to the list;
void add_film(List filmlist, Film * item);

// print the list of films in original order
void list_films(List filmlist);

// print the list of films in reverse order
void reverse_list_films(List filmlist);

#endif