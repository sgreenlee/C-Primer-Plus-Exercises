/* C Primer Plus

Chapter 4 Exercise 8:

Write a program that asks the user to enter the number of miles traveled and
the number of gallons of gasoline consumed. It should then calculate and
display the miles-per-gallon value, showing one place to the right of the
decimal. Next, using the fact that one gallon is about 3.785 liters and one
mile is about 1.609 kilometers, it should convert the mile- per-gallon value
to a liters-per-100-km value, the usual European way of expressing fuel
consumption, and display the result, showing one place to the right of the
decimal. Note that the U. S. scheme measures the distance traveled per amount
of fuel (higher is better), whereas the European scheme measures the amount of
fuel per distance (lower is better). Use symbolic constants (using const or
#define) for the two conversion factors. */

#include <stdio.h>

int main(void)
{
	const float KM_PER_MILE = 1.609;
	const float LT_PER_GALLON = 3.785;
	float miles_travelled, gallons_gas_consumed;
	float miles_per_gallon, liters_per_100km;

	printf("Enter your distance travelled in miles: ");
	scanf("%f", &miles_travelled);
	printf("Enter the amount of gas consumed in gallons: ");
	scanf("%f", &gallons_gas_consumed);

	// calculate miles per gallon and liters per km
	miles_per_gallon = miles_travelled / gallons_gas_consumed;
	liters_per_100km = 100. / miles_per_gallon * LT_PER_GALLON / KM_PER_MILE;

	printf("Miles per gallon: %.1f\n", miles_per_gallon);
	printf("Liters per 100 kilometers: %.1f\n", liters_per_100km);

	return 0;
}