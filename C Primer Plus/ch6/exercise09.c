// C Primer Plus
// Chapter 6 Exercise 9:

// Modify exercise 8 so that it uses a function to return the value of the
// calculation.

#include <stdio.h>

float calculate(float n1, float n2);

int main(void)
{
	float num1, num2;
	int reads;
	
	printf("Enter two floating-point numbers: ");
	while (scanf(" %f %f", &num1, &num2) == 2)
	{
		printf("(%.3f - %.3f)/(%.3f * %.3f) = %.3f\n", num1, num2, num1, num2,
		       calculate(num1, num2));
		printf("Enter two floating-point numbers (enter non-numeric to quit): ");
	}

	return 0;
}

float calculate(float n1, float n2)
{
	return (n1 - n2) / (n1 * n2);
}
