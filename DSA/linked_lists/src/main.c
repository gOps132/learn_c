/**
 * IMPLEMENTATION FROM THE C PROGRAMMING LANGUAGE BOOK
 * 2ND EDITION
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_BUFFER 100

typedef struct list_t {
	int value;
	struct list_t *next;
} list_t;

void insert(list_t *a, list_t *b)
{
	a->next = b;
}

void func(int *b)
{
	// copies a, doesnt have any effect on the value of the address
	*b = 2;
}

int main(int argc, char** argv)
{
	// int a = 1;
	// func(&a);

	list_t a = { 1, NULL };
	list_t b = { 8, NULL };
	
	insert(&a, &b);

	printf("%d", a.next->value);
	return 0;
}
