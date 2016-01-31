// C Primer Plus
// Chapter 14 Exercise 3:

// Revise the book-listing program in Listing 14.2 so that it prints the book
// descriptions in the order entered, then alphabetized by title, and then in
// order of increased value.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * get(char *, int);
void titlesort(struct book **books, int count);
void valuesort(struct book **books, int count);

int main(void)
{
	struct book *library[MAXBKS];
	char temp[MAXTITL];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [ENTER] at the start of a line to stop.\n");
	while (count < MAXBKS && get(temp, MAXTITL) != NULL
		   && temp[0] != '\0')
	{
		library[count] = (struct book *) malloc(sizeof(struct book));
		strncpy(library[count]->title, temp, MAXTITL);

		printf("Now enter the author.\n");
		get(library[count]->author, MAXAUTL);

		printf("Now enter the value.\n");
		scanf("%f", &library[count]->value);

		while (getchar() != '\n')
			continue;

		if (count < MAXBKS)
			printf("Enter the next title.\n");

		count++;
	}

	if (count > 0)
	{
		printf("Here is the list of your books in the original order:\n");
		for (int i = 0; i < count; i++)
			printf("%s by %s: $%.2f\n", library[i]->title, library[i]->author,
				   library[i]->value);
		puts("");

		// sorted by title
		printf("Here is the list of your books alphabetized by title:\n");
		titlesort(library, count);
		for (int i = 0; i < count; i++)
			printf("%s by %s: $%.2f\n", library[i]->title, library[i]->author,
				   library[i]->value);
		puts("");

		// sorted by value
		printf("Here is the list of your books ordered by value:\n");
		valuesort(library, count);
		for (int i = 0; i < count; i++)
			printf("%s by %s: $%.2f\n", library[i]->title, library[i]->author,
				   library[i]->value);
	}
	else
		printf("No books? Too bad.\n");

	for (int i = 0; i < count; i++)
		free(library[count]);

	return 0;
}


char * get(char *string, int n)
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

void titlesort(struct book **books, int count)
{
	struct book *temp;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (tolower(books[i]->title[0]) > tolower(books[j]->title[0]))
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

void valuesort(struct book **books, int count)
{
	struct book *temp;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (books[i]->value > books[j]->value)
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}