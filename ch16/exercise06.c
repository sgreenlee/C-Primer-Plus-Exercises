// C Primer Plus
// Chapter 16 Exercise 6:

// Modify Listing 16.17 so that it uses an array of struct names elements (as
// defined after the listing) instead of an array of double. Use fewer
// elements, and initialize the array explicitly to a suitable selection of
// names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 15

typedef struct name {
	char first[40];
	char last[40];
} NAME;

int comparenames(const void * p1, const void * p2);
void printnames(const NAME * arr, int arr_size);

int main(void)
{
	NAME insideout[NUM] = {
		{"Amy", "Poehler"},
		{"Phyllis", "Smith"},
		{"Richard", "Kind"},
		{"Bill", "Hader"},
		{"Lewis", "Black"},
		{"Mindy", "Kaling"},
		{"Kaitlyn", "Dias"},
		{"Diane", "Lane"},
		{"Kyle", "MacLachlan"},
		{"Paula", "Poundstone"},
		{"Bobby", "Moynihan"},
		{"Paula", "Pell"},
		{"Dave", "Goelz"},
		{"Frank", "Oz"},
		{"Josh", "Cooley"},
	};

	puts("Here is the list of names:");
	printnames(insideout, NUM);
	puts("");

	qsort(insideout, NUM, sizeof(NAME), comparenames);

	puts("Here is the sorted list of names:");
	printnames(insideout, NUM);
}

int comparenames(const void * p1, const void * p2)
{
	NAME * name1 = (NAME *) p1;
	NAME * name2 = (NAME *) p2;

	int c = strcmp(name1->last, name2->last);
	return c ? c : strcmp(name1->first, name2->first);
}

void printnames(const NAME * arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		printf("%s, %s\n", arr[i].last, arr[i].first);
}