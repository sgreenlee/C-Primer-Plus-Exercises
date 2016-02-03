// C Primer Plus
// Chapter 14 Exercise 10:

// Write a program that implements a menu by using an array of pointers to
// functions. For instance, choosing a from the menu would activate the
// function pointed to by the first element of the array.


#include <stdio.h>
#include <math.h>
#define NOPTIONS 5

void menu(void);
double sum(double, double);
double difference(double, double);
double power(double, double);
double product(double, double);
double quotient(double, double);

int main(void)
{
	// declare array of function pointers
	double (*funcs[NOPTIONS])(double, double) = {sum, difference, product, quotient,
											     power};
	double x, y;
	int ch;

	
	while (1)
	{
		menu();
		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;
		ch -= 'a';
		if (ch < 0 || ch > 5)
		{
			puts("This is not a valid option. Try again.");
			continue;
		}
		else if (ch == 5)
			break;
		
		printf("Enter two numbers: ");
		while(scanf("%lf %lf", &x, &y) != 2)
		{
			while (getchar() != '\n') continue;
			printf("Invalid input. Enter two numbers: ");
		}
		while (getchar() != '\n') continue;

		printf("%f\n", funcs[ch](x, y));
		puts("");
	}
	puts("Bye.");
}

void menu(void)
{
	puts("Choose an operation:");
	puts("a) add");
	puts("b) subtract");
	puts("c) multiply");
	puts("d) divide");
	puts("e) power");
	puts("f) quit");
	return;
}

double sum(double x, double y)
{
	return x + y;
}

double difference(double x, double y)
{
	return x - y;
}

double power(double x, double y)
{
	return pow(x, y);
}

double product(double x, double y)
{
	return x * y;
}

double quotient(double x, double y)
{
	return x / y;
}