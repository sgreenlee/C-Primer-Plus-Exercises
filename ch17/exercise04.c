// C Primer Plus
// Chapter 17 Exercise 4:

// Rewrite mall.c (Listing 17.7) so that it simulates a double booth having two
// queues.

// mall.c -- use the Queue interface // compile with queue.c

#include <stdio.h>
#include <stdlib.h> 				// for rand() and srand()
#include <time.h>					// for time()
#include "queue.h"					// change Item typedef

#define MIN_PER_HR 60.0

bool newcustomer(double x); 		// is there a new customer?
Item customertime(long when);		// set customer parameters

int main(void) {
	Queue line1, line2;
	Item temp;						// new customer data
	int hours;						// hours of simulation
	int perhour;					// average # of arrivals per hour 
	long cycle, cyclelimit; 		// loop counter, limit
	long turnaways = 0; 			// turned away by full queue
	long customers = 0;				// joined the queue
	long served1 = 0;				// served in line 1 during the simulation
	long served2 = 0;				// served in line 2 during the simulation
	long sum_line1 = 0;				// cumulative line 1 length
	long sum_line2 = 0;				// cumulative line 2 length
	int wait_time1 = 0;				// time until Sigmund is free
	int wait_time2 = 0;				// time until Sigmund 2 is free
	double min_per_cust;			// average time between arrivals 
	long line_wait1 = 0;			// cumulative time in line 1
	long line_wait2 = 0;			// cumulative time in line 2
 
	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int) time(0)); 	// random initializing of rand()

	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line1) & QueueIsFull(&line2)) {
				turnaways++;
			}
			else {
				// add customer to shorter queue
				temp = customertime(cycle);
				if (QueueItemCount(&line1) <= QueueItemCount(&line2)) {
					EnQueue(temp, &line1);
				}
				else {
					EnQueue(temp, &line2);
				}
				customers++;
			}
		}
		if (wait_time1 <= 0 && !QueueIsEmpty(&line1)) {
			DeQueue (&temp, &line1);
			wait_time1 = temp.processtime;
			line_wait1 += cycle - temp.arrive;
			served1++;
		}
		if (wait_time2 <= 0 && !QueueIsEmpty(&line2)) {
			DeQueue (&temp, &line2);
			wait_time2 = temp.processtime;
			line_wait2 += cycle - temp.arrive;
			served2++;
		}
		if (wait_time1 > 0) {
			wait_time1--;
		}
		if (wait_time2 > 0) {
			wait_time2--;
		}
		sum_line1 += QueueItemCount(&line1);
		sum_line2 += QueueItemCount(&line2);
	}

	if (customers > 0) {
		printf("customers accepted: %ld\n", customers);
		printf("total customers served: %ld\n", served1 + served2);
		printf("turnaways: %ld\n", turnaways);
		printf("line 1 customers served: %ld\n", served1);
		printf("line 2 customers served: %ld\n", served2);
		printf("average queue size for line 1: %.2f\n", (double) sum_line1 / cyclelimit);
		printf("average queue size for line 2: %.2f\n", (double) sum_line2 / cyclelimit);
		printf("line 1 average wait time: %.2f minutes\n", (double) line_wait1 / served1);
		printf("line 2 average wait time: %.2f minutes\n", (double) line_wait2 / served2);
	}
	else {
		puts("No customers!");
	}
	
	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Bye!");

	return 0;
}


// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) {
	if (rand() * x / RAND_MAX < 1) {
		return true;
	}
	else {
		return false;
	}
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when) {
	Item cust;
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;
	return cust;
}