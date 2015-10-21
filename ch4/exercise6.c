/* C Primer Plus

Chapter 4 Exercise 6:

Write a program that requests the user’s first name and then the user’s last
name. Have it print the entered names on one line and the number of letters in
each name on the following line. Align each letter count with the end of the
corresponding name, as in the following:

    Melissa Honeybee 
          7        8

Next, have it print the same information, but with the counts aligned with the
beginning of each name.

    Melissa Honeybee 
    7       8

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char first_name[20];
	char last_name[20];

	printf("Enter your first and last name: ");
	scanf("%s %s", first_name, last_name);
	printf("\n");
	printf("%s %s\n", first_name, last_name);
	printf("%*lu %*lu\n", // right justified
		   (int) strlen(first_name), strlen(first_name),
		   (int) strlen(last_name), strlen(last_name));
	printf("\n");
	printf("%s %s\n", first_name, last_name);
	printf("%-*lu %-*lu\n", // left justified
		   (int) strlen(first_name), strlen(first_name),
		   (int) strlen(last_name), strlen(last_name));
	printf("\n");

	return 0;
}
