// C Primer Plus
// Chapter 7 Exercise 3:

// Write a program that reads integers until 0 is entered. After input
// terminates, the program should report the total number of even integers
// (excluding the 0) entered, the average value of the even integers, the total
// number of odd integers entered, and the average value of the odd integers.

#include <stdio.h>
#include <ctype.h>

#define STOP 0

int main(void)
{
	int even_count = 0, even_sum = 0, odd_count = 0, odd_sum = 0;
	float even_avg, odd_avg;
	int input;

	printf("Enter integers (0 to stop):\n");
	while(scanf("%d", &input) == 1 && input != STOP)
	{
		if (input % 2 == 0)
		{
			even_count++;
			even_sum += input;
		}
		else
		{
			odd_count++;
			odd_sum += input;
		}
	}

	even_avg = even_sum / (float) even_count;
	odd_avg = odd_sum / (float) odd_count;

	printf("Number of even integers: %d\n", even_count);
	printf("Average value of even integers: %.2f\n", even_avg);
	printf("Number of odd integers: %d\n", odd_count);
	printf("Average value of odd integers: %.2f\n", odd_avg);

	return 0;
}
