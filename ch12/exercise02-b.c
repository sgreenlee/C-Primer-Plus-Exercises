
#include <stdio.h>
#include "exercise02.h"

#define METRIC 0
#define US 1

static int mode;
static double distance;
static double fuel;

void clear_input_stream(void)
{
	while (getchar() != '\n')
		continue;
}

void set_mode(int new_mode)
{
	extern int mode;
	if (new_mode == METRIC || new_mode == US)
		mode = new_mode;
	else
		printf("Invalid mode specified. Mode %d(%s) used.\n",
			mode, mode == METRIC ? "metric" : "US");
}

void get_info(void)
{
	printf("Enter distance travelled in %s: ",
		mode == METRIC ? "kilometers" : "miles");
	while (scanf("%lf", &distance) != 1)
	{
		clear_input_stream();
		printf("Invalid input. Enter distance travelled in %s: ",
			mode == METRIC ? "kilometers" : "miles");
	}

	printf("Enter fuel consumed in %s: ",
		mode == METRIC ? "liters" : "gallons");
	while (scanf("%lf", &fuel) != 1)
	{
		clear_input_stream();
		printf("Invalid input. Enter fuel consumed in %s: ",
			mode == METRIC ? "liters" : "gallons");
	}
}

void show_info(void)
{
	double efficiency;

	if (mode == METRIC)
	{
		efficiency = fuel / distance * 100;
		printf("Fuel consumption is %.3f liters per 100 kilometers.\n",
			efficiency);
	}
	else if (mode == US)
	{
		efficiency = distance / fuel;
		printf("Fuel consumption is %.3f miles per gallon.\n",
			efficiency); 
	}
	else
	{
		printf("Error. Invalid mode: %d\n", mode);
	}

}