// C Primer Plus
// Chapter 14 Exercise 1:

// Redo Review Question 5, but make the argument the spelled-out name of the
// month instead of the month number. (Don’t forget about strcmp().) Test the
// function in a simple program.

// Review Question 5:
// Write a function that, when given the month number, returns the total days
// in the year up to and including that month. Assume that the structure
// template of question 3 and an appropriate array of such structures are
// declared externally.

// Review Question 3:
// Devise a structure template that will hold the name of a month, a three-
// letter abbreviation for the month, the number of days in the month, and the
// month number.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MONTHS 12
#define LEN 20
#define ABREV_LEN 3

int daysupto(const char *);
void get(char *, int);

struct month {
	char name[LEN];
	char abr[ABREV_LEN];
	int month_no;
	int days;
};

struct month months[MONTHS];
int days_in_month[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *names[MONTHS] = {"January", "February", "March", "April", "May",
					   "June", "July", "August", "September", "October",
					   "November", "December"};
char *abrevs[MONTHS] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                        "Aug", "Sep", "Oct", "Nov", "Dec"};

int main(void){

	char monthname[LEN];
	int totaldays;

	printf("Enter the full name of a month, capitalized (eg. March): ");
	get(monthname, LEN);

	totaldays = daysupto(monthname);

	if (totaldays != 0)
		printf("There are %d days in the year up to and including %s.\n",
			   totaldays, monthname);
	else
		printf("There is no month named %s\n", monthname);

	puts("Bye.");
	return 0;
}

int daysupto(const char *monthname){
	
	// takes a string containing the name of a month and returns
	// the total days in the year up to and including that month

	// initialize array of month structs
	for (int i = 0; i < MONTHS; i++)
	{
		strncpy(months[i].name, names[i], LEN);
		strncpy(months[i].abr, abrevs[i], ABREV_LEN);
		months[i].month_no = i + 1;
		months[i].days = days_in_month[i];
	}

	int totaldays = 0;

	for (int i = 0; i < MONTHS; i++)
	{
		totaldays += months[i].days;

		// if month_name matches name of current month, return count of days
		if (strcmp(monthname, months[i].name) == 0)
			return totaldays;
	}

	// no match found, return 0
	return 0;
}

void get(char * string, int n)
{
	// wrapper for fgets - read from stdin and replace
	// first newline with null character

	fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}
		string++;
	}
}
