/**
 * Take all the characters from both arrays without a similar character pairing
 * and put them in another array so that they dont feel rejected.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_BUFFER 100

/**
void check_unique(char* unique_arr, char* arr, int bound, int *index)
{
	// check if any characters inside each array has a duplicate
	// no need for strlen since we specified the size
	for(int i = 0; i < bound; i++)
	{
		int is_unique = 1;
		for(int j = 0; j < bound; j++)
		{
			if (j != i && arr[i] == arr[j])
			{
				is_unique = 0;
				break;
			}
		}
		if (is_unique)
		{
			unique_arr[*index] = arr[i];
			(*index)++;
		}
	}
}
**/

int main()
{
	char arr1[MAX_CHAR_BUFFER], arr2[MAX_CHAR_BUFFER];
	char concat[MAX_CHAR_BUFFER], unique_char[MAX_CHAR_BUFFER];

	int e1;
	printf("Enter number of elements in first array: ");
	scanf(" %d", &e1);    
	for (int i = 0; i < e1; i++)    
	{
		scanf(" %c", &arr1[i]);
	}
	arr1[e1] = '\0';

	int e2;
	printf("Enter number of elements in second array: ");
	scanf(" %d", &e2);
	for (int i = 0; i < e2; i++)    
	{
		scanf(" %c", &arr2[i]);
	}
	arr2[e2] = '\0';

/**
	int min = 0, max = e1 + e2;
	char *min_arr;
	char *max_arr;
	if (e1 > e2)
	{
		min = e2;
		max_arr = arr2;
	} else {
		min = e1;
		max_arr = arr1;
	}
	// (i + (i * 1)) is accounting for two values in
	for(int i = 0; i < max; i++)
	{
		if (i <= min)
		{
			concat[(i + (i * 1))] = arr1[i];
			concat[(i + (i * 1))+1] = arr2[i];
		} else {
			concat[(min + (min * 1))+i] = max_arr[i];
		}
	}


	int index = 0;
	int bound = strlen(concat);
	for (int i = 0 < bound; i++)
	{
		concat[i] = tolower(concat[i]);
	}
	// check_unique(unique_char, concat, strlen(concat), &index);
	for(int i = 0; i < bound; i++)
	{
		int is_unique = 1;
		for(int j = 0; j < bound; j++)
		{
			if (j != i && concat[i] == concat[j])
			{
				is_unique = 0;
				break;
			}
		}
		if (is_unique)
		{
			unique_char[index] = concat[i];
			index++;
		}
	}

	printf("Unique characters = ");
	for (int i = 0; i < index; i++)
	{
		printf("%c ", unique_char[i]);
	}
	printf("\n");

	return 0;
}