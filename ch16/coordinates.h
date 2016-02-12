// coordinates.h 

#ifndef COORDINATES_H_
#define COORDINATES_H_

typedef struct polar 
{
	double angle;
	double magnitude;
} Polar;

typedef struct cartesian
{
	double x;
	double y;
} Cartesian;


// 	Cartesian cartesianFromPolar(Polar):
// 	converts polar coordinates to cartesian

Cartesian cartesianFromPolar(Polar coords); 

#endif