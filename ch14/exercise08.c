// C Primer Plus
// Chapter 14 Exercise 8:

// The Colossus Airlines fleet consists of one plane with a seating capacity of
// 12. It makes one flight daily. Write a seating reservation program with the
// following features:

// a. The program uses an array of 12 structures. Each structure should hold a
// seat identification number, a marker that indicates whether the seat is
// assigned, the last name of the seat holder, and the first name of the seat
// holder.

// b. The program displays the following menu:
// 	To choose a function, enter its letter label: 
// 	a) Show number of empty seats
// 	b) Show list of empty seats
// 	c) Show alphabetical list of seats
// 	d) Assign a customer to a seat assignment 
//  e) Delete a seat assignment
// 	f) Quit

// c. The program successfully executes the promises of its menu. Choices d)
// and e) require additional input, and each should enable the user to abort an
// entry.

// d. After executing a particular function, the program shows the menu again,
// except for choice f).

// e. Data is saved in a file between runs. When the program is restarted, it
// first loads in the data, if any, from the file.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CAPACITY 12
#define MAXNAML 20

struct Seat
{
	int id;
	bool assigned;
	char last[MAXNAML];
	char first[MAXNAML];
};

int size = sizeof(struct Seat);

struct Seat seats[CAPACITY];

char * get(char *, int);

void printmenu(void);
void countempty(void);
void listempty(void);
void showalphabetical(void);
void assigncustomer(void);
void deleteassignment(void);

int main(void)
{
	FILE * fp;
	int ch = 0;
	int id;
	struct Seat tmp;

	for (int i = 0; i < CAPACITY; i++)
	{
		seats[i].id = i;
		seats[i].assigned = false;
	}

	if ((fp = fopen("seatassignments.dat", "rb")) == NULL)
	{
		fprintf(stderr, "Could not open file 'seatassignments.dat'.\n");
		exit(EXIT_FAILURE);
	}

	// read saved data into seats array
	while (fread(&tmp, size, 1, fp) == 1)
	{
		seats[tmp.id] = tmp;
	}

	// main program loop
	while (ch != 'f' && ch != 'F')
	{
		printmenu();
		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;
		switch (ch)
		{
			case ('a'):
			case ('A'):
				countempty();
				break;
			case ('b'):
			case ('B'):
				listempty();
				break;
			case ('c'):
			case ('C'):
				showalphabetical();
				break;
			case ('d'):
			case ('D'):
				assigncustomer();
				break;
			case ('e'):
			case ('E'):
				deleteassignment();
				break;
			case ('f'):
			case ('F'):
				break;
			default:
				puts("Invalid input. Try again.");
		}
		puts("");

	}

	fclose(fp);
	if ((fp = fopen("seatassignments.dat", "wb")) == NULL)
	{
		fprintf(stderr, "Could not open file 'seatassignments.dat' for write.\n");
		exit(EXIT_FAILURE);
	}

	if (fwrite(seats, size, CAPACITY, fp) != CAPACITY)
	{
		fprintf(stderr, "Error writing to file 'seatassignments.dat'.\n");
	}

	fclose(fp);
	puts("Bye.");

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

void printmenu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Quit");
}

void countempty(void)
{
	int count = 0;
	for (int i = 0; i < CAPACITY; i++)
		if (!seats[i].assigned)
			count++;
	printf("%d\n", count);
}

void listempty(void)
{
	for (int i = 0; i < CAPACITY; i++)
		if (!seats[i].assigned)
			printf("Seat number %d is unassigned.\n", seats[i].id);
}

void showalphabetical(void)
{
	printf("%-*s  %-*s  %-12s\n", MAXNAML, "Last Name", MAXNAML, "First Name",
		   "Seat Number");
	for (int i = 0; i < CAPACITY; i++)
	{
		if (seats[i].assigned)
			printf("%-*s  %-*s  %-12d\n", MAXNAML, seats[i].last, MAXNAML,
				   seats[i].first, seats[i].id);
	}
}

void assigncustomer(void)
{
	int id, ch;
	struct Seat new;

	printf("Enter seat id number: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
		return;
	}
	if (seats[id].assigned)
	{
		puts("This seat is already assigned. Aborting.");
		return;
	}

	new.id = id;
	new.assigned = true;
	printf("Enter passenger first name: ");
	get(new.first, MAXNAML);
	printf("Enter passenger last name: ");
	get(new.last, MAXNAML);

	puts("Here is the overview for your new seat assignment:");
	printf("Seat number: %d  First name: %s  Last name: %s\n", new.id,
		   new.first, new.last);
	puts("Is this correct? Enter [n/N] to abort or any other key to continue.");
	
	if ((ch = getchar()) != '\n')
		while (getchar() != '\n') continue;
	if (ch == 'n' || ch == 'N')
	{
		puts("Aborting seat assignment.");
		return;
	}
	seats[id] = new;
	return;
}

void deleteassignment(void)
{
	int id, ch = 0;
	puts("Enter seat number of the assignment to delete: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
		return;
	}
	if (!seats[id].assigned)
	{
		puts("This seat is not currently assigned. Aborting.");
		return;
	}
	puts("Here is the seat assignment you have selected:");
	printf("Seat number: %d  First name: %s  Last name: %s\n", seats[id].id,
		   seats[id].first, seats[id].last);
	puts("Would you like to delete this assignment? Enter [n/N] to abort "
		 "or any other key to continue.");
	if ((ch = getchar()) != '\n')
		while (getchar() != '\n') continue;
	if (ch == 'n' || ch == 'N')
	{
		puts("Aborting seat assignment.");
		return;
	}
	seats[id].first[0] = '\0';
	seats[id].last[0] = '\0';
	seats[id].assigned = false;

	return;
}