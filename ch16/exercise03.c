// C Primer Plus
// Chapter 16 Exercise 3:

// Polar coordinates describe a vector in terms of magnitude and the
// counterclockwise angle from the x-axis to the vector. Rectangular
// coordinates describe the same vector in terms of x and y components (see
// Figure 16.3). Write a program that reads the magnitude and angle (in
// degrees) of a vector and then displays the x and y components. The relevant
// equations are these:
// 	x = r cos A y = r sin A
// To do the conversion, use a function that takes a structure containing the
// polar coordinates and returns a structure containing the rectangular
// coordinates (or use pointers to such structures, if you prefer).

// compile with coordinates.c

#include <stdio.h>
#include "exercise01.h"
#include "coordinates.h"

int main()
{
	Polar polar_coords;
	Cartesian cartesian_coords;

	printf("Enter an angle: ");
	while (scanf("%lf", &polar_coords.angle) == 1)
	{
		CLEARINPUT;
		printf("Enter a magnitude: ");
		while (scanf("%lf", &polar_coords.magnitude) != 1)
		{
			CLEARINPUT;
			printf("Enter a magnitude: ");
		}

		cartesian_coords = cartesianFromPolar(polar_coords);

		printf("angle: %.2f  magnitude: %.2f\n", polar_coords.angle,
			   polar_coords.magnitude);
		printf("x: %.2f  y: %.2f\n", cartesian_coords.x, cartesian_coords.y);

		printf("Enter an angle: ");
	}
	puts("Bye.");
}