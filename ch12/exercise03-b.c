
#include <stdio.h>
#include "exercise03.h"

#define METRIC 0
#define US 1
#define QUIT -1

void clear_input_stream(void)
{
	while (getchar() != '\n')
		continue;
}

void set_mode(int *mode)
{
	int new_mode = 2;
	printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");

	if (scanf("%d", &new_mode) != 1)
		clear_input_stream();

	if (new_mode == METRIC || new_mode == US || new_mode == QUIT)
		*mode = new_mode;
	else
	{
		printf("Invalid mode specified. Mode %d(%s) used.\n",
			*mode, *mode == METRIC ? "metric" : "US");
	}

}

void get_info(int mode, double *distance, double *fuel)
{
	printf("Enter distance travelled in %s: ",
		mode == METRIC ? "kilometers" : "miles");
	while (scanf("%lf", distance) != 1)
	{
		clear_input_stream();
		printf("Invalid input. Enter distance travelled in %s: ",
			mode == METRIC ? "kilometers" : "miles");
	}

	printf("Enter fuel consumed in %s: ",
		mode == METRIC ? "liters" : "gallons");
	while (scanf("%lf", fuel) != 1)
	{
		clear_input_stream();
		printf("Invalid input. Enter fuel consumed in %s: ",
			mode == METRIC ? "liters" : "gallons");
	}
}

void show_info(int mode, double distance, double fuel)
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