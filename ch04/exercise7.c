/* C Primer Plus

Chapter 4 Exercise 7:

Write a program that sets a type double variable to 1.0/3.0 and a type float
variable to 1.0/3.0. Display each result three times—once showing four digits
to the right of the decimal, once showing 12 digits to the right of the decimal,
and once showing 16 digits to the right of the decimal. Also have the program
include float.h and display the values of FLT_DIG and DBL_DIG. Are the displayed
values of 1.0/3.0 consistent with these values? */

#include <stdio.h>
#include <float.h>

int main(void)
{
	double db_one_third = 1.0 / 3.0;
	float ft_one_third = 1.0 / 3.0;

	printf("Float                Double              \n");
	printf("-------------------- --------------------\n");
	printf("%-20.4f %-20.4f\n", ft_one_third, db_one_third); // show 4 digits
	printf("%-20.12f %-20.12f\n", ft_one_third, db_one_third); // show 12 digits
	printf("%-20.16f %-20.16f\n", ft_one_third, db_one_third);
	printf("\n");
	printf("FLT_DIG: %d\n", FLT_DIG);
	printf("DBL_DIG: %d\n", DBL_DIG);

	/* results: both float and double are accurate to at least the amount of sig
	figs specified by FLT_DIG and DBL_DIG */

	return 0;
}
