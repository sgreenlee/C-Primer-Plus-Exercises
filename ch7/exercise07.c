// C Primer Plus
// Chapter 7 Exercise 7:

// Write a program that requests the hours worked in a week and then prints the
// gross pay, the taxes, and the net pay. Assume the following:
// a. Basic pay rate = $10.00/hr
// b. Overtime (in excess of 40 hours) = time and a half
// c. Tax rate: #15% of the first $300
// 	20% of the next $150 25% of the rest
// Use #define constants, and don’t worry if the example does not conform to
// current tax law.

#include <stdio.h>

#define BASIC_RATE 10.0
#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLIER 1.5
#define TAX_RATE_1 0.15
#define TAX_BRACKET_1 300.0
#define TAX_RATE_2 0.20
#define TAX_BRACKET_2 450.0
#define TAX_RATE_3 0.25

float calculate_gross_pay(float hours);
float calulate_taxes(float gross_pay);

int main(void)
{
	float hours, gross_pay, taxes;

	printf("Enter number of hours worked in a week: ");

	if (scanf("%f", &hours) == 1)
	{
		gross_pay = calculate_gross_pay(hours);
		taxes = calulate_taxes(gross_pay);

		printf("For %.1f hours of work you make $%.2f and pay $%.2f in taxes.\n",
			   hours, gross_pay, taxes);
	}
	else
		printf("Invalid input...terminating.\n");

	return 0;
}

float calculate_gross_pay(float hours)
{
	if (hours > OVERTIME_HOURS)
		return OVERTIME_HOURS * BASIC_RATE + (hours - OVERTIME_HOURS) * BASIC_RATE * OVERTIME_MULTIPLIER;
	else
		return hours * BASIC_RATE;
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
