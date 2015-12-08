// C Primer Plus
// Chapter 12 Exercise 3:

// Redesign the program described in Programming Exercise 2 so that it uses
// only automatic variables. Have the program offer the same user interface—
// that is, it should prompt the user to enter a mode, and so on. You’ll have
// to come up with a different set of function calls, however.


// compile with exercise02-b.c

#include <stdio.h>
#include "exercise03.h"

int main(void)
{
	int mode = 0;
	double distance, fuel;

	set_mode(&mode);
	while (mode >= 0)
	{
		get_info(mode, &distance, &fuel);
		show_info(mode, distance, fuel);
		set_mode(&mode);
	}

	printf("Done.\n");
	return 0; 
}