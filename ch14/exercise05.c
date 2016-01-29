// C Primer Plus
// Chapter 14 Exercise 5:

// Write a program that fits the following recipe:
// a. Externally define a name structure template with two members: a string to
// 	hold the first name and a string to hold the second name.
// b. Externally define a student structure template with three members: a name
// 	structure, a grade array to hold three floating-point scores, and a
// 	variable to hold the average of those three scores.
// c. Have the main() function declare an array of CSIZE (with CSIZE = 4)
// 	student structures and initialize the name portions to names of your
// 	choice. Use functions to perform the tasks described in parts d., e.,
// 	f., and g.
// d. Interactively acquire scores for each student by prompting the user with
// 	a student name and a request for scores. Place the scores in the grade
// 	array portion of the appropriate structure. The required looping can be
// 	done in main() or in the function, as you prefer.
// e. Calculate the average score value for each structure and assign it to the
// 	proper member.
// f. Print the information in each structure.
// g. Print the class average for each of the numeric structure members.

#include <stdio.h>

#define CSIZE 4
#define NAMELEN 20
#define GRADELEN 3

struct Name
{
	char first[NAMELEN];
	char last[NAMELEN];
};

struct Student
{
	struct Name name;
	float grades[GRADELEN];
	float average;
};

void getgrades(struct Student *);
void getaverage(struct Student *);
void showstudentinfo(struct Student *);

int main(void)
{
	struct Student students[CSIZE] = {
		{.name = {"Zack", "Morris"}},
		{.name = {"Kelly", "Kapowski"}},
		{.name = {"AC", "Slater"}},
		{.name = {"Screech", "Powers"}}
	};

	// get student grades
	for (int i = 0; i < CSIZE; i++)
		getgrades(&students[i]);

	// get grade averages
	for (int i = 0; i < CSIZE; i++)
		getaverage(&students[i]);

	// print student info
	for (int i = 0; i < CSIZE; i++)
		showstudentinfo(&students[i]);

	return 0;
}

void getgrades(struct Student * student)
{
	// interactively acquire and set grades for student

	for (int i = 0; i < GRADELEN; i++)
	{
		printf("Enter grade %d for student %s %s: ", i + 1, student->name.first,
			   student->name.last);
		while (scanf("%f", student->grades+i) != 1)
			while (getchar() != '\n') continue;
		while (getchar() != '\n') continue;
	}
	puts("");
}

void getaverage(struct Student * student)
{
	// calculate and set the average grade for a student

	float total = 0;
	for (int i = 0; i < GRADELEN; i++)
		total += student->grades[i];
	student->average = total / GRADELEN;
}

void showstudentinfo(struct Student * student)
{
	printf("Name: %s %s\n", student->name.first, student->name.last);
	printf("Grade 1: %.1f\n", student->grades[0]);
	printf("Grade 2: %.1f\n", student->grades[1]);
	printf("Grade 3: %.1f\n", student->grades[2]);
	printf("Average Grade: %.1f\n", student->average);
	puts("");
}