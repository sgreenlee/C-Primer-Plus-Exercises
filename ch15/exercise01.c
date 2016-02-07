// C Primer Plus
// Chapter 15 Exercise 1:

// Write a function that converts a binary string to a numeric value. That is,
// if you have
//     char * pbin = "01001001";
// you can pass pbin as an argument to the function and have the function
// return an int value of 25.

// NOTE: "01001001" in base10 is actually 73

#include <stdio.h>

int parsebinarystring(const char * string);

int main(void)
{
	// test parsebinarystring()
	int result;
	char * binstring = "01001001";
	printf("%s in base-10 is %d.\n", binstring, parsebinarystring(binstring));

	return 0;
}

int parsebinarystring(const char * string)
{
	// convert a binary string to a numeric value

	int retval = 0;
	while (*string != '\0')
	{
		retval <<= 1;
		if (*string == '1')
			retval |= 1;
		string++;
	}
	return retval;
}