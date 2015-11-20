// C Primer Plus
// Chapter 7 Exercise 11:

// The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for
// $1.15 per pound, and carrots for $1.09 per pound. It gives a 5% discount for
// orders of $100 or more prior to adding shipping costs. It charges $6.50
// shipping and handling for any order of 5 pounds or under, $14.00 shipping
// and handling for orders over 5 pounds and under 20 pounds, and $14.00 plus
// $0.50 per pound for shipments of 20 pounds or more. Write a program that
// uses a switch statement in a loop such that a response of a lets the user
// enter the pounds of artichokes desired, b the pounds of beets, c the pounds
// of carrots, and q allows the user to exit the ordering process. The program
// should keep track of cumulative totals. That is, if the user enters 4 pounds
// of beets and later enters 5 pounds of beets, the program should use report 9
// pounds of beets. The program then should compute the total charges, the
// discount, if any, the shipping charges, and the grand total. The program
// then should display all the purchase information: the cost per pound, the
// pounds ordered, and the cost for that order for each vegetable, the total
// cost of the order, the discount (if there is one), the shipping charge, and
// the grand total of all the charges.

#include <stdio.h>
#include <stdbool.h>

#define ARTICHOKE_PRICE_PER_LB 2.05
#define BEET_PRICE_PER_LB 1.15
#define CARROT_PRICE_PER_LB 1.09

#define SHIPPING_5LB 6.50
#define SHIPPING_20LB 14.00
#define SHIPPING_OVER_20LB_RATE 0.5

#define DISCOUNT_RATE 0.05

void flush_input_buffer(void);
float calculate_shipping(float weight);

int main(void)
{
	float artichoke_weight = 0, beet_weight = 0, carrot_weight = 0, total_weight;
	float artichoke_price, beet_price, carrot_price, subtotal, discount, shipping, total;
	bool discount_flag;
	float weight;
	char option;

	printf("ABC Mail Order Grocery\n");
	while(1)
	{
		printf("What would you like to order?\n");
		printf("a) artichokes  b) beets  c) carrots  q) quit\n");
		option = getchar();
		switch (option)
		{
			case ('q') : 
					printf("Bye.\n");
					return 0; // exit program

			case ('a') : // artichokes
					printf("How many pounds of artichokes would you like to add? ");
					if (scanf("%f", &weight) == 1)
						artichoke_weight += weight;
					else
					{
						flush_input_buffer();
						printf("Invalid input. Try again.\n");
						continue; // repeat main program loop
					}
					break;

			case ('b') : // beets
					printf("How many pounds of beets would you like to add? ");
					if (scanf("%f", &weight) == 1)
						beet_weight += weight;
					else
					{
						flush_input_buffer();
						printf("Invalid input. Try again.\n");
						continue; // repeat main program loop
					}
					break;

			case ('c') : // carrots
					printf("How many pounds of carrots would you like to add? ");
					if (scanf("%f", &weight) == 1)
						carrot_weight += weight;
					else
					{
						flush_input_buffer();
						printf("Invalid input. Try again.\n");
						continue; // repeat main program loop
					}
					break;

			default :
					printf("Invalid input. Try again.\n");
					continue; // repeat main program loop
		}

		// calculate subtotal
		artichoke_price = artichoke_weight * ARTICHOKE_PRICE_PER_LB;
		beet_price = beet_weight * BEET_PRICE_PER_LB;
		carrot_price = carrot_weight * CARROT_PRICE_PER_LB;
		subtotal = artichoke_price + beet_price + carrot_price;

		// calculate discount
		if (subtotal >= 100)
		{
			discount_flag = true;
			discount = DISCOUNT_RATE * subtotal;
		}
		else
			discount_flag = false;

		// calculate shipping
		total_weight = artichoke_weight + beet_weight + carrot_weight;
		shipping = calculate_shipping(total_weight);

		// grand total
		total = subtotal + shipping - (discount_flag ? discount : 0.0);

		printf("\n");
		printf("Your order summary:\n\n");
		printf("Artichokes: %.2flbs @ $%.2f/lb: $%.2f\n",
			   artichoke_weight, ARTICHOKE_PRICE_PER_LB, artichoke_price);
		printf("Beets: %.2flbs @ $%.2f/lb: $%.2f\n",
			   beet_weight, BEET_PRICE_PER_LB, beet_price);
		printf("Carrots: %.2flbs @ $%.2f/lb: $%.2f\n",
			   carrot_weight, CARROT_PRICE_PER_LB, carrot_price);
		printf("\n");
		printf("Subtotal: $%.2f\n", subtotal);
		if (discount_flag)
			printf("%.0f%% discount: $%.2f\n", DISCOUNT_RATE * 100, discount);
		printf("Shipping charges: $%.2f\n", shipping);
		printf("Grand total: $%.2f\n", total);
		printf("\n");

		flush_input_buffer();
	}
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}

float calculate_shipping(float weight)
{
	if (weight < 5.0)
		return SHIPPING_5LB;
	else if (weight < 20.0)
		return SHIPPING_20LB;
	else
		return SHIPPING_20LB + SHIPPING_OVER_20LB_RATE * (weight - 20.0);
}
