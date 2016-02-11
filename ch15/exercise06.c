// C Primer Plus:
// Chapter 15 Exercise 6:

// Design a bit-field structure that holds the following information:
// 	  Font ID: A number in the range 0–255
// 	  Font Size: A number in the range 0–127
// 	  Alignment: A number in the range 0–2 represented the choices Left,
// 	    Center, and Right
//    Bold: Off (0) or on (1)
// 	  Italic: Off (0) or on (1)
// 	  Underline: Off (0) or on (1)
// Use this structure in a program that displays the font parameters and uses a
// looped menu to let the user change parameters. For example, a sample run
// might look like this:

// 	   ID SIZE ALIGNMENT  B   I   U 
//     1  12   left      off off off
    
//     f)change fonts	s)change size 	 a)change alignment
//     b)toggle bold 	i)toggle italic  u)toggle underline
// 	   q)quit
// 	   s
// 	   Enter font size (0-127): 36

// 	   ID SIZE ALIGNMENT  B   I   U 
//     1  36   left      off off off

//     f)change fonts	s)change size 	 a)change alignment
//     b)toggle bold 	i)toggle italic  u)toggle underline
// 	   q)quit
// 	   a
// 	   Select alignment:
// 	   l)left    c)center   r)right
// 	   r
// 	   ...

#include <stdio.h>

#define CLEARINPUT while (getchar() != '\n') continue

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define ALSTR(al) al ? (al == 1 ? "center" : "right") : "left"

#define OFF 0
#define ON 1
#define ONOFF(status) status? "on" : "off"

typedef struct {
	unsigned int id: 			8;
	unsigned int size: 			7;
	unsigned int alignment:		2;
	unsigned int bold:			1;
	unsigned int italic:		1;
	unsigned int underline:		1;
} Font;

void display_font(Font *);
void print_menu(void);
void setfont(Font *);
void setsize(Font *);
void setalignment(Font *);
void togglebold(Font *);
void toggleitalic(Font *);
void toggleunderline(Font *);

int main()
{
	Font font = { 1, 12, 1, 0, 0, 0};

	while(1)
	{
		display_font(&font);
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
			togglebold(&font);
		else if (ch == 'i')
			toggleitalic(&font);
		else if (ch == 'u')
			toggleunderline(&font);
		else
			puts("Sorry, I don't understand that input. Try again.");
	}

	puts("Bye.");
	return 0;
}

void display_font(Font * font)
{
	puts("");
	puts("ID  SIZE ALIGNMENT  B   I   U ");
	printf("%-3u %-4u %-9s %3s %3s %3s\n", font->id, font->size,
		   ALSTR(font->alignment), ONOFF(font->bold), ONOFF(font->italic),
		   ONOFF(font->underline));
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
	font->id = id;
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
	font->size = size;
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
		font->alignment = LEFT;
	else if (ch == 'c')
		font->alignment = CENTER;
	else if (ch == 'r')
		font->alignment = RIGHT;

	CLEARINPUT;
}

void togglebold(Font * font)
{
	font->bold = font->bold ? OFF : ON;
}

void toggleitalic(Font * font)
{
	font->italic = font->italic ? OFF : ON;
}
void toggleunderline(Font * font)
{
	font->underline = font->underline ? OFF : ON;
}