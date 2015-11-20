// C Primer Plus
// Chapter 8 Exercise 8

// Write a program that shows you a menu offering you the choice of addition,
// subtraction, multiplication, or division. After getting your choice, the
// program asks for two numbers, then performs the requested operation. The
// program should accept only the offered menu choices. It should use type
// float for the numbers and allow the user to try again if he or she fails to
// enter a number. In the case of division, the program should prompt the user
// to enter a new value if 0 is entered as the value for the second number.

#include <stdio.h>
#include <ctype.h>

int get_first(void);
void print_menu(void);
float get_number(void);

int main(void)
{
	int operation;
	float num1, num2;

	print_menu();
	while ((operation = get_first()) != 'q')
	{
		printf("Enter first number: ");
		num1 = get_number();
		printf("Enter second number: ");
		num2 = get_number();

		switch (operation)
		{
			case ('a') :
				printf("%.3f + %.3f = %.3f\n", num1, num2, num1 + num2);
				break;
			case ('s') :
				printf("%.3f - %.3f = %.3f\n", num1, num2, num1 - num2);
				break;
			case ('m') :
				printf("%.3f * %.3f = %.3f\n", num1, num2, num1 * num2);
				break;
			case ('d') :
				while (num2 == 0)
				{
					printf("Enter a number other than 0: ");
					num2 = get_number();
				}
				printf("%.3f / %.3f = %.3f\n", num1, num2, num1 / num2);
				break;
			default :
				printf("I do not recognize that input. Try again.");
		}
		print_menu();
	}


}

int get_first(void)
{
	// return first non-whitespace character
	int ch;

	do ch = getchar(); while (isspace(ch));

	while (getchar() != '\n')
		;

	return ch;
}


void print_menu(void)
{
	printf("Enter the operation of your choice:\n");
	printf("a. add            s. subtract\n");
	printf("m. multiply       d. divide\n");
	printf("q. quit\n");
}

float get_number(void)
{
	int ch;
	float num;

	while (scanf("%f", &num) != 1)
	{
		while ((ch = getchar()) != '\n') // echo user input and clear stream
			putchar(ch);

		printf(" is not a number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}

	return num;
}