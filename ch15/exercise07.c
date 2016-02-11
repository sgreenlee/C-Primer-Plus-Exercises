// C Primer Plus:
// Chapter 15 Exercise 7:

// Write a program with the same behavior as described in exercise 6, but use
// an unsigned long variable to hold the font information and use the bitwise
// operators instead of bit members to manage the information.

#include <stdio.h>

#define CLEARINPUT while (getchar() != '\n') continue

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define OFF 0
#define ON 1
#define ONOFF(status) status? "on" : "off"

#define ID_SHIFT 0
#define SIZE_SHIFT 8
#define ALIGN_SHIFT 15
#define BOLD_SHIFT 18
#define ITAL_SHIFT 19
#define UNDERL_SHIFT 20

#define ID_MSK (255U << ID_SHIFT)
#define SIZE_MSK (127U << SIZE_SHIFT)
#define ALIGN_MSK (3U << ALIGN_SHIFT)
#define BOLD_MSK (1U << BOLD_SHIFT)
#define ITAL_MSK (1U << ITAL_SHIFT)
#define UNDERL_MSK (1U << UNDERL_SHIFT)

#define getid(font) ((font & ID_MSK) >> ID_SHIFT)
#define getsize(font) ((font & SIZE_MSK) >> SIZE_SHIFT)
#define getalign(font) ((font & ALIGN_MSK) >> ALIGN_SHIFT)
#define getalignstr(font) (getalign(font) ? (getalign(font) == CENTER ? "center" : "right") : "left")
#define getbold(font) ((font & BOLD_MSK) >> BOLD_SHIFT)
#define getital(font) ((font & ITAL_MSK) >> ITAL_SHIFT)
#define getunderline(font) ((font & UNDERL_MSK) >> UNDERL_SHIFT)
#define setid_(font, id) (font &= ~ID_MSK, font |= ((id << ID_SHIFT) & ID_MSK))
#define setsize_(font, size) (font &= ~SIZE_MSK, font |= ((size << SIZE_SHIFT) & SIZE_MSK))
#define setalign_(font, align) (font &= ~ALIGN_MSK, font |= ((align << ALIGN_SHIFT) & ALIGN_MSK))
#define togglebold(font) (font ^= BOLD_MSK)
#define toggleital(font) (font ^= ITAL_MSK)
#define toggleunderline(font) (font ^= UNDERL_MSK)


typedef unsigned int Font;

void display_font(Font);
void print_menu(void);
void setfont(Font *);
void setsize(Font *);
void setalignment(Font *);

int main()
{
	Font font =  0;
	setid_(font, 1);
	setsize_(font, 12);
	setalign_(font, 1);

	while(1)
	{
		display_font(font);
		print_menu();
		int ch = getchar();
		if (ch != '\n')
			CLEARINPUT;

		if (ch == EOF || ch =='q') // exit conditions
			break;
		else if (ch == 'f')
			setfont(&font);
		else if (ch == 's')
			setsize(&font);
		else if (ch == 'a')
			setalignment(&font);
		else if (ch == 'b')
			togglebold(font);
		else if (ch == 'i')
			toggleital(font);
		else if (ch == 'u')
			toggleunderline(font);
		else
			puts("Sorry, I don't understand that input. Try again.");
	}

	puts("Bye.");
	return 0;
}

void display_font(Font font)
{
	puts("");
	puts("ID  SIZE ALIGNMENT  B   I   U ");
	printf("%-3u %-4u %-9s %3s %3s %3s\n", getid(font), getsize(font),
		   getalignstr(font), ONOFF(getbold(font)), ONOFF(getital(font)),
		   ONOFF(getunderline(font)));
	puts("");
}

void print_menu(void)
{
	puts("f)change fonts	s)change size 	 a)change alignment");
	puts("b)toggle bold 	i)toggle italic  u)toggle underline");
	puts("q)quit");
}

void setfont(Font * font)
{
	unsigned int id;
	printf("Enter font id (0 - 255): ");
	while (scanf("%u", &id) != 1)
	{
		CLEARINPUT;
		puts("Invalid input. Try again.");
		printf("Enter font id (0 - 255): ");
	}
	setid_(*font, id);
	CLEARINPUT;
}

void setsize(Font * font)
{
	unsigned int size;
	printf("Enter font size (0 - 127): ");
	while (scanf("%u", &size) != 1)
	{
		CLEARINPUT;
		puts("Invalid input. Try again.");
		printf("Enter font size (0 - 127): ");
	}
	setsize_(*font, size);
	CLEARINPUT;
}

void setalignment(Font * font)
{
	puts("Select alignment:");
	puts("l)left   c)center   r)right");
	int ch;
	while (!((ch = getchar()) == 'l' || ch == 'c' || ch == 'r')) 
	{
		puts("That is not a valid option. Try again.");
		puts("Select alignment:");
		puts("l)left   c)center   r)right");
	}

	if (ch == 'l')
		setalign_(*font, LEFT);
	else if (ch == 'c')
		setalign_(*font, CENTER);
	else if (ch == 'r')
		setalign_(*font, RIGHT);

	CLEARINPUT;
}
