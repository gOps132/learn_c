/**
 * IMPLEMENTATION FROM THE C PROGRAMMING LANGUAGE BOOK
 * 2ND EDITION
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int highest_num(int size, int *arr)
{
	int tmp;
	tmp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > tmp)
			tmp = arr[i];
	}
	return tmp;
}

int smallest_num(int size, int *arr)
{
	int tmp;
	tmp = arr[0];
	for (int *i = arr; i < arr + size; i++)
	{
		if (*i < tmp)
			tmp = *i;
	}
	return tmp;
}

int main(int argc, char** argv)
{
	
	int size;
	printf("Enter size of the array: ");
	scanf("%d", &size);
	// int arr[size];
	int *arr;
	// sizeof(int)
	arr = calloc(size, sizeof(*arr));
	if (arr == NULL)
	{
		perror("Instantiating dynamic array failed!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("The highest number in your array is: %d\n", smallest_num(size, arr));

	// int *a = NULL;
	// for (a = arr; a < arr + size; a++)
	// {
	// 	printf(" %d ", *a);
	// }
	
	// int loc;
	// printf("Enter element location: ");
	// scanf(" %d", &loc); 
	// if (loc >= size)
	// 	return 1;
	// printf("%d\n", *(arr+loc));

	free(arr);

	return 0;
}
