// C Primer Plus
// Chapter 14 Exercise 9:

// Colossus Airlines (from exercise 8) acquires a second plane (same capacity)
// and expands its service to four flights daily (Flights 102, 311, 444, and
// 519). Expand the program to handle four flights. Have a top-level menu that
// offers a choice of flights and the option to quit. Selecting a particular
// flight should then bring up a menu similar to that of exercise 8. However,
// one new item should be added: confirming a seat assignment. Also, the quit
// choice should be replaced with the choice of exiting to the top-level menu.
// Each display should indicate which flight is currently being handled. Also,
// the seat assignment display should indicate the confirmation status.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FLIGHTS 4
#define CAPACITY 12
#define MAXNAML 20

struct Seat
{
	int id;
	bool assigned;
	bool confirmed;
	char last[MAXNAML];
	char first[MAXNAML];
};

struct Flight
{
	int id;
	struct Seat seats[CAPACITY];
};

struct Flight flights[FLIGHTS] = {
	{102, {}},
	{311, {}},
	{444, {}},
	{519, {}}
};

int flight_size = sizeof(struct Flight);

static struct Flight * flight;

char * get(char *, int);

void print_top_menu(void);
void flightmenu(void);
void printmenu(void);
void countempty(void);
void listempty(void);
void showalphabetical(void);
void assigncustomer(void);
void deleteassignment(void);
void confirmassignment(void);

int main(void)
{
	FILE * fp;
	int ch = 0, id;
	extern struct Flight * flight;
	struct Flight tmp;

	for (int i = 0; i < FLIGHTS; i++)
		for (int j = 0; j < CAPACITY; j++)
		{
			flights[i].seats[j].id = j;
			flights[i].seats[j].assigned = false;
		}

	if ((fp = fopen("Colossus.dat", "rb")) == NULL)
	{
		fprintf(stderr, "Could not open file 'Colossus.dat'.\n");
		exit(EXIT_FAILURE);
	}

	// read saved data into flights array
	while (fread(&tmp, flight_size, 1, fp) == 1)
	{
		int number = tmp.id;
		for (int i = 0; i < FLIGHTS; i++)
		{
			if (flights[i].id == number)
			{
				flights[i] = tmp;
				break;
			}
		}
	}

	// main program loop
	while (ch != 'e' && ch != 'E')
	{
		print_top_menu();
		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;
		puts("");
		switch (ch)
		{
			case ('a'):
			case ('A'):
				flight = &flights[0];
				break;
			case ('b'):
			case ('B'):
				flight = &flights[1];
				break;
			case ('c'):
			case ('C'):
				flight = &flights[2];
				break;
			case ('d'):
			case ('D'):
				flight = &flights[3];
				break;
			case ('e'):
			case ('E'):
				goto Exit;
			default:
				puts("Invalid input. Try again.");
				continue;
		}
		
		flightmenu();
	}

	Exit:
	fclose(fp);
	if ((fp = fopen("Colossus.dat", "wb")) == NULL)
	{
		fprintf(stderr, "Could not open file 'Colossus.dat' for write.\n");
		exit(EXIT_FAILURE);
	}

	if (fwrite(flights, flight_size, FLIGHTS, fp) != FLIGHTS)
	{
		fprintf(stderr, "Error writing to file 'Colossus.dat'.\n");
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

void print_top_menu(void)
{
	puts("To choose a flight, enter its letter label:");
	puts("a) 102");
	puts("b) 311");
	puts("c) 444");
	puts("d) 519");
	puts("e) Quit");

	return;
}

void flightmenu(void)
{
	int ch = 0;
	extern struct Flight * flight;

	while (ch != 'g' && ch != 'G')
	{	
		printf("You have selected flight number %d.\n", flight->id);
		puts("To choose a function, enter its letter label:");
		puts("a) Show number of empty seats");
		puts("b) Show list of empty seats");
		puts("c) Show alphabetical list of seats");
		puts("d) Assign a customer to a seat assignment");
		puts("e) Delete a seat assignment");
		puts("f) Confirm a seat assignment");
		puts("g) Back to main menu");

		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;
		puts("");
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
				confirmassignment();
				break;
			case ('g'):
			case ('G'):
				break;
			default:
				puts("Invalid input. Try again.");
		}
	}
	return;
}

void countempty(void)
{
	extern struct Flight * flight;

	// count empty seats on flight
	int count = 0;
	for (int i = 0; i < CAPACITY; i++)
		if (!flight->seats[i].assigned)
			count++;
	printf("There are %d empty seats on flight number %d.\n", count, flight->id);
}

void listempty(void)
{
	extern struct Flight * flight;
	// list empty seats
	printf("Here is a list of empty seats on flight number %d:\n", flight->id);
	for (int i = 0; i < CAPACITY; i++)
		if (!flight->seats[i].assigned)
			printf("Seat number %d is unassigned.\n", flight->seats[i].id);
}

void showalphabetical(void)
{
	extern struct Flight * flight;

	printf("Here is a list of seat assignments for flight number %d:\n", flight->id);
	printf("%-*s  %-*s  %-12s %-12s\n", MAXNAML, "Last Name", MAXNAML, "First Name",
		   "Seat Number", "Status");
	for (int i = 0; i < CAPACITY; i++)
	{
		if (flight->seats[i].assigned)
			printf("%-*s  %-*s  %-12d %-12s\n", MAXNAML, flight->seats[i].last, 
				   MAXNAML, flight->seats[i].first, flight->seats[i].id,
				   flight->seats[i].confirmed ? "Confirmed" : "Unconfirmed");
	}
}

void assigncustomer(void)
{
	int id, ch;
	struct Seat new;
	extern struct Flight * flight;

	printf("Enter seat id number: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
		return;
	}
	if (flight->seats[id].assigned)
	{
		puts("This seat is already assigned. Aborting.");
		return;
	}

	new.id = id;
	new.assigned = true;
	new.confirmed = false;
	printf("Enter passenger first name: ");
	get(new.first, MAXNAML);
	printf("Enter passenger last name: ");
	get(new.last, MAXNAML);

	puts("Here is the overview for your new seat assignment:");
	printf("Flight number: %d\nSeat number: %d\nFirst name: %s\n"
		   "Last name: %s\n", flight->id, new.id, new.first, new.last);
	puts("Is this correct? Enter [n/N] to abort or any other key to continue.");
	
	if ((ch = getchar()) != '\n')
		while (getchar() != '\n') continue;
	if (ch == 'n' || ch == 'N')
	{
		puts("Aborting seat assignment.");
		return;
	}
	flight->seats[id] = new;
	return;
}

void deleteassignment(void)
{
	int id, ch = 0;
	extern struct Flight * flight;

	puts("Enter seat number of the assignment to delete: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
		return;
	}
	if (!flight->seats[id].assigned)
	{
		puts("This seat is not currently assigned. Aborting.");
		return;
	}
	puts("Here is the seat assignment you have selected:");
	printf("Flight number: %d\nSeat number: %d\nFirst name: %s\n"
		   "Last name: %s\n", flight->id, flight->seats[id].id,
		   flight->seats[id].first, flight->seats[id].last);
	puts("Would you like to delete this assignment? Enter [n/N] to abort "
		 "or any other key to continue.");
	if ((ch = getchar()) != '\n')
		while (getchar() != '\n') continue;
	if (ch == 'n' || ch == 'N')
	{
		puts("Aborting seat assignment.");
		return;
	}
	flight->seats[id].first[0] = '\0';
	flight->seats[id].last[0] = '\0';
	flight->seats[id].assigned = false;
	flight->seats[id].confirmed = false;

	return;
}

void confirmassignment(void)
{
	int id;
	extern struct Flight * flight;

	printf("Enter seat id number to confirm: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
	}
	else if (!flight->seats[id].assigned)
	{
		puts("There is no current assignment for this seat. Aborting.");
	}
	else if (flight->seats[id].confirmed)
	{
		puts("This seat assignment is already confirmed.");
	}
	else
	{
		flight->seats[id].confirmed = true;
		puts("Your assignment has been confirmed.");
	}
	return;
}
