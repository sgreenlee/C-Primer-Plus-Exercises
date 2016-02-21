// C Primer Plus
// Chapter 17 Exercise 7:

// Write a program that opens and reads a text file and records how many times
// each word occurs in the file. Use a binary search tree modified to store
// both a word and the number of times it occurs. After the program has read
// the file, it should offer a menu with three choices. The first is to list
// all the words along with the number of occurrences. The second is to let you
// enter a word, with the program reporting how many times the word occurred in
// the file. The third choice is to quit.

// compile with tree.c

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"

void printMenu(void);
int getOption(void);
void printWordCount(Item item);
char * toLowercase(char * string);
char * get(char * string, int n);

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	FILE * fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Could not open file '%s'.\n", argv[1]);
		exit(1);
	}

	char tmp[WORD_SIZE];
	Tree words;
	Tree * ptree = InitializeTree(&words);
	while (fscanf(fp, "%s", tmp) == 1) {
		toLowercase(tmp);
		if (!AddWord(tmp, ptree)) {
			fprintf(stderr, "Could not add word to search tree.\n");
			exit(1);
		}
	}

	int ch;
	char word[WORD_SIZE];
	while ((ch = getOption()) != 'q') {
		if (ch == 'a') {
			ApplyToAll(ptree, printWordCount);
		} else if (ch == 'b') {
			printf("Enter a word to search for: ");
			get(word, WORD_SIZE);
			ApplyToNode(word, ptree, printWordCount);
		}
		puts("");
	}
	puts("Bye.");
}

void printMenu(void) {
	puts("Options:");
	puts("a) List all words with their respective counts");
	puts("b) Search for a word");
	puts("q) Quit");
	printf("Select an option: ");
}

int getOption(void) {
	printMenu();
	int opt;
	while ((opt = getchar()) != 'a' && opt != 'b' && opt != 'q') {
		puts("That is not a valid option. Try again.");
		printf("Select an option: ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	return opt;
}

void printWordCount(Item item) {
	printf("%s: %d\n", item.word, item.count);
}

char * toLowercase(char * string) {
	char * retval = string;
	for (; *string != '\0'; string++) {
		*string = tolower(*string);
	}
	return retval;
}

char * get(char * string, int n) {
	// wrapper for fgets - read from stdin and replace
	// first newline with null character

	char * retval = fgets(string, n, stdin);

	for (; *string != '\0'; string++) {
		if (*string == '\n') {
			*string = '\0';
			break;
		}
	}
	return retval;
}