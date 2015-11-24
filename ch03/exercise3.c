/* C Primer Plus

Chapter 3 Exercise 3:

Write a program that sounds an alert and then prints the following text: Startled by the sudden sound, Sally shouted,
"By the Great Pumpkin, what was that!" */

#include <stdio.h>
int main(void)

{
	printf("\a"); // sound alert
	printf("Startled by the sudden sound, Sally shouted, \"By the Great Pumpkin, what was that!\"\n");

	return 0;
}
