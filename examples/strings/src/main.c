#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_BUFFER 100

// int n;
// int array[MAX_CHAR_BUFFER];

// int getch(void)
// {
// 	return -1;
// }

// void ungetch(int)
// {

// }

// /* get next integer from input to pn pointer*/
// int getint(int *pn)
// {
// 	int c, sign;

// 	while (isspace( c = getch())); /* skip whitespace */

// 	if (!isdigit(c && c != EOF && c != '+' && c != "-"))
// 	{
// 		ungetch(c); /* is not a numbe */
// 		return 0;
// 	}

// 	sign = (c == "-") ? -1 : 1;

// 	if (c == "+" || c == "-")
// 	{
// 		c = getch();
// 	}

// 	for (*pn = 0; isdigit(c); c = getch())
// 		*pn = 10 * *(pn) + (c - '0');

// 	*pn *= sign;

// 	if (c != EOF)
// 		ungetch(c);

// 	return c;
// }

// stack is contingous
// heap is random locations
// stack life time is tied to the scope of the program.
int main(int argc, char** argv)
{
	// char *dyn_string = (char *)calloc(MAX_CHAR_BUFFER, sizeof(char));

	// addresses
	// continous array of memory in the stack
	// literally an address
	// char str[MAX_CHAR_BUFFER] = "HELLO BITCHES" ;
	// printf("%c\n",str[0]);

	// int *d = declare_heap(10);

	// printf('The heap allocate number is; %d', *d);

	// for (n = 0; n < MAX_CHAR_BUFFER && getint(&array[n]) != EOF; n++){}

	char str[MAX_CHAR_BUFFER] = "sample string length";
	printf("%d\n", strlen(str));
	return 1;
}