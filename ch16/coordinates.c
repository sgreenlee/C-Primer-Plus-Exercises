// coordinates.c -- implementation file for polar and cartesian coordinates

#include "coordinates.h"
#include <math.h>

Cartesian cartesianFromPolar(Polar coords)
{
	Cartesian retval;

	retval.x = coords.magnitude * cos(coords.angle);
	retval.y = coords.magnitude * sin(coords.angle);

	return retval;
}