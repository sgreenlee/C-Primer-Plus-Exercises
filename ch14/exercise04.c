// C Primer Plus
// Chapter 14 Exercise 4:

// Write a program that creates a structure template with two members according
// to the following criteria:
// a. The first member is a social security number. The second member is a
// structure with three members. Its first member contains a first name, its
// second member contains a middle name, and its final member contains a last
// name. Create and initialize an array of five such structures. Have the
// program print the data in this format:
// Dribble, Flossie M. –– 302039823
// Only the initial letter of the middle name is printed, and a period is
// added. Neither the initial (of course) nor the period should be printed if
// the middle name member is empty. Write a function to do the printing; pass
// the structure array to the function.
// b. Modify part a. by passing the structure value instead of the address.

#include <stdio.h>
#include <ctype.h>

#define LEN 5
#define MAXNAME 20

struct Name
{
	char first[MAXNAME];
	char middle[MAXNAME];
	char last[MAXNAME];
};

struct Person
{
	int ssn;
	struct Name name;
};

void printpersona(struct Person *); // pass struct by address
void printpersonb(struct Person); // pass struct by value

int main(void)
{
	struct Person people[LEN] = {
		{123456789, {"Marvin", "The", "Martian"}},
		{987654321, {"Scrooge", "Mc", "Duck"}},
		{888777666, {"Mantis", "Froggy", "Tobogan"}},
		{123432467, {.first="Night", .last="Man"}},
		{354257623, {.first="Day", .last="Man"}}
	};

	// part a -- pass by address
	for (int i = 0; i < LEN; i++)
		printpersona(&people[i]);
	puts("");

	// part b -- pass by value
	for (int i = 0; i < LEN; i++)
		printpersonb(people[i]);

	return 0;
}


void printpersona(struct Person *person)
{
	printf("%s, %s ", person->name.last, person->name.first);
	if (person->name.middle[0] != '\0')
		printf("%c. ", toupper(person->name.middle[0]));
	printf("--- %d\n", person->ssn);
}

void printpersonb(struct Person person)
{
	printf("%s, %s ", person.name.last, person.name.first);
	if (person.name.middle[0] != '\0')
		printf("%c. ", toupper(person.name.middle[0]));
	printf("--- %d\n", person.ssn);
}