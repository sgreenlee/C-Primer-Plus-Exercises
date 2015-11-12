// C Primer Plus
// Chapter 9 Exercise 10:

// Generalize the to_binary() function of Listing 9.8 to a to_base_n() function
// that takes a second argument in the range 2–10. It then should print the
// number that is its first argument to the number base given by the second
// argument. For example, to_ base_n(129,8) would display 201, the base-8
// equivalent of 129. Test the function in a complete program.


#include <stdio.h>
#include <stdlib.h>

void to_base_n(int integer, int base);

int main(void) {
	int integer, base;

	printf("Test to_base_n() function\n");
	printf("Enter an integer in base 10 and a base to convert to: ");
	while (scanf("%d %d", &integer, &base) == 2)
	{
		to_base_n(integer, base);
		putchar('\n');

		printf("Enter an integer in base 10 and a base to convert to: ");
	}

	return 0;
}

void to_base_n(int integer, int base)
{
	// handle invalid bases
	if (base < 2 || 10 < base)
	{
		printf("Error: base must be between 2 and 10.");
		return;
	}

	// stop recursion
	if (integer == 0) return;

	// handle negative integers
	if (integer < 0)
	{
		putchar('-');
		integer = abs(integer);
	}

	to_base_n(integer / base, base);
	printf("%d", integer % base);
	return;

}