// C Primer Plus
// Chapter 8 Exercise 7:

// Modify Programming Exercise 8 from Chapter 7 so that the menu choices are
// labeled by characters instead of by numbers; use q instead of 5 as the cue
// to terminate input.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define RATE_1 8.75
#define RATE_2 9.33
#define RATE_3 10.00
#define RATE_4 11.20

#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLIER 1.5
#define TAX_RATE_1 0.15
#define TAX_BRACKET_1 300.0
#define TAX_RATE_2 0.20
#define TAX_BRACKET_2 450.0
#define TAX_RATE_3 0.25

void flush_input_buffer(void);
float calculate_gross_pay(float hours, float rate);
float calulate_taxes(float gross_pay);
int get_first(void);

int main(void)
{
	bool exit_flag = false;
	int rate_option;
	float rate, hours, gross_pay, taxes;

	while (1) // main program loop
	{

		// print usage instructions
		printf("********************************************************************\n");
		printf("Enter the character corresponding to the desired pay rate or action:\n");
		printf("a) $%.2f/hr 				b) $%.2f/hr\n", RATE_1, RATE_2);
		printf("c) $%.2f/hr 				d) $%.2f/hr\n", RATE_3, RATE_4);
		printf("q) quit \n");
		printf("********************************************************************\n");

		rate_option = get_first();
		switch (rate_option)
		{
			case ('a') : 	
				rate = RATE_1;
				break;
			case ('b') : 	
				rate = RATE_2;
				break;
			case ('c') :
				rate = RATE_3;
				break;
			case ('d') :
				rate = RATE_4;
				break;
			case ('q') :
				printf("Bye.\n");
				return 0; // exit program
			default : // invalid input
				printf("Invalid input. Try again.\n\n");
				continue; // repeat main program loop
		}

		printf("Enter number of hours worked in a week: ");
		while (scanf("%f", &hours) != 1 || hours <= 0)
		{
			flush_input_buffer();
			printf("Please enter a positive number. \n");
			printf("Enter number of hours worked in a week: ");
		}

		gross_pay = calculate_gross_pay(hours, rate);
		taxes = calulate_taxes(gross_pay);

		printf("For %.1f hours of work at $%.2f/hr, you make $%.2f and pay"
			   " $%.2f in taxes.\n", hours, rate, gross_pay, taxes);
		printf("\n");

	}
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}

float calculate_gross_pay(float hours, float rate)
{
	if (hours > OVERTIME_HOURS)
		return OVERTIME_HOURS * rate + (hours - OVERTIME_HOURS) * rate * OVERTIME_MULTIPLIER;
	else
		return hours * rate;
}

float calulate_taxes(float gross_pay)
{
	if (gross_pay > TAX_BRACKET_2)
		return TAX_RATE_3 * (gross_pay - TAX_BRACKET_2) + TAX_RATE_2 * (TAX_BRACKET_2 - TAX_BRACKET_1) + TAX_RATE_1 * TAX_BRACKET_1;
	else if (gross_pay > TAX_BRACKET_1)
		return TAX_RATE_2 * (gross_pay - TAX_BRACKET_1) + TAX_RATE_1 * TAX_BRACKET_1;
	else
		return TAX_RATE_1 * gross_pay;
}

int get_first(void)
{
	// returns first non-whitespace character and clears
	// remaining input until next line break or EOF

	int ch, garbage;

	do {
		ch = getchar();
	}
	while (isspace(ch));
		

	while((garbage = getchar()) != '\n' && garbage != EOF)
		;

	return ch;
}
