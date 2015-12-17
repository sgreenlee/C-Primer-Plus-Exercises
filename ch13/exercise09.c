// C Primer Plus
// Chapter 13 Exercise 9:

// Modify the program in Listing 13.3 so that each word is numbered according
// to the order in which it was added to the list, starting with 1. Make sure
// that, when the program is run a second time, new word numbering resumes
// where the previous numbering left off.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void) 
{
	FILE *fp;
	char words[MAX];
	char line[MAX + 6];
	int word_count = 1;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout,"Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	// count lines already written to file
	rewind(fp);
	while (fgets(line, MAX + 6, fp) != NULL)
		word_count++;
	
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin,"%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%d %s\n", word_count++, words);

	puts("File contents:");
	rewind(fp); /* go back to beginning of file */
	while (fgets(line, MAX + 6, fp) != NULL)
		fputs(line, stdout);
	puts("Done!");
	
	if (fclose(fp) != 0)
		fprintf(stderr,"Error closing file\n");
	
	return 0; 
}
