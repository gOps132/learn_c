/**
 * IMPLEMENTATION FROM THE C PROGRAMMING LANGUAGE BOOK
 * 2ND EDITION
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_BUFFER 100

// particular binary search function  decides if particular value x occurs in
// the sorted array v 

int count = 1;

int bin_search(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low <= high)
	{
		count++;
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

// peculariar how the binary search works, basically a n% chance for it to work

int main(int argc, char** argv)
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int result = bin_search(1,arr,5);
	if(result > 0)
		printf("found number: %d\ncount: %d\n", arr[result], count);
	else
		printf("not found!\n");
	
	return 1;
}
