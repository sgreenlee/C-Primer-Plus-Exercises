// C Primer Plus
// Chapter 14 Exercise 6:

// A text file holds information about a softball team. Each line has data
// arranged as follows:
// 	4 Jessie Joybat 5 2 1 1
// The first item is the player’s number, conveniently in the range 0–18. The
// second item is the player’s first name, and the third is the player’s last
// name. Each name is a single word. The next item is the player’s official
// times at bat, followed by the number of hits, walks, and runs batted in
// (RBIs). The file may contain data for more than one game, so the same player
// may have more than one line of data, and there may be data for other players
// between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and
// last names, the at bats, hits, walks, and RBIs (runs batted in), and the
// batting average (to be calculated later). You can use the player number as
// an array index. The program should read to end- of-file, and it should keep
// cumulative totals for each player.

// The world of baseball statistics is an involved one. For example, a walk or
// reaching base on an error doesn’t count as an at-bat but could possibly
// produce an RBI. But all this program has to do is read and process the data
// file, as described next, without worrying about how realistic the data is.

// The simplest way for the program to proceed is to initialize the structure
// contents to zeros, read the file data into temporary variables, and then add
// them to the contents of the corresponding structure. After the program has
// finished reading the file, it should then calculate the batting average for
// each player and store it in the corresponding structure member. The batting
// average is calculated by dividing the cumulative number of hits for a player
// by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each
// player along with a line showing the combined statistics for the entire
// team.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 12
#define ROSTERSIZE 19
#define MXLINE 40

struct Player
{
	char first[NAMELEN];
	char last[NAMELEN];
	unsigned int atbats, hits, walks, rbis;
	float battingaverage;
};

void getbattingaverage(struct Player *);
void showteamdata(const struct Player *, int);

int main(void)
{
	// declare and initialize array of players
	struct Player players[ROSTERSIZE];
	for (int i = 0; i < ROSTERSIZE; i++)
		players[i] = (struct Player) {"", "", 0, 0, 0, 0, 0};

	FILE *fp;
	int number;
	char first[NAMELEN];
	char last[NAMELEN];
	unsigned int atbats;
	unsigned int hits;
	unsigned int walks;
	unsigned int rbis;

	if ((fp = fopen("roster.txt", "r")) == NULL)
	{
		fprintf(stderr, "Could not open file 'roster.txt'.\n");
		exit(EXIT_FAILURE);
	}

	// read data from roster.txt
	while (fscanf(fp, "%d %s %s %u %u %u %u", &number, first, last, &atbats,
		          &hits, &walks, &rbis) == 7)
	{
		if (players[number].first[0] == '\0')
		{
			strncpy(players[number].first, first, NAMELEN);
			strncpy(players[number].last, last, NAMELEN);
		}
		players[number].atbats += atbats;
		players[number].hits += hits;
		players[number].walks += walks;
		players[number].rbis += rbis;
	}

	// calculate batting averages
	for (int i = 0; i < ROSTERSIZE; i++)
		getbattingaverage(&players[i]);

	// print player data
	showteamdata(players, ROSTERSIZE);

	if (fclose(fp) != 0)
		fprintf(stderr,"Error closing file\n");

	return 0;
}

void getbattingaverage(struct Player * player)
{
	player->battingaverage = player->hits / (float) player->atbats;
}

void showteamdata(const struct Player * player, int size)
{
	unsigned int atbats = 0, hits = 0, walks = 0, rbis = 0;

	printf("Team statistics (number, first, last, at bats, hits, walks,"
		   " rbis, average):\n");
	for (int i = 0; i < size; i++, player++)
	{
		printf("%2d ", i);
		printf("%*s %*s %u %u %u %u %.3f\n", NAMELEN, player->first, NAMELEN,
		       player->last, player->atbats, player->hits, player->walks,
		       player->rbis, player->battingaverage);

		atbats += player->atbats;
		hits += player->hits;
		walks += player->walks,
		rbis += player->rbis;
	}
	printf("Combined stats: %u %u %u %u %.3f\n", atbats, hits, walks, rbis,
		   hits / (float) atbats);
}