/*
 * (n+1)C(r) = nC(r-1) + (n)Cr
*/

#include <stdio.h>
#include <math.h>

int factorial(int n)
{
	if (n == 0)
		return 1;
	// 5  5*4*3*2*1
	int a = n;
	for(int i = n-1; i > 1; i--)
	{
		a *= i;
		// combinations(n, i);
	}
	return a;
}

int combinations(int n, int k)
{
	int a = factorial(n);
	int b = factorial(k);
	// dont divide by zero
	
	return a / (b * factorial(n-k));
}

void pascals(int rows)
{
	// n = column
	// r = row (i)
	// int spaces = (rows/2)+2;
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 1; j <= rows - i; j++)
		{
			printf(" ");
		}
		// spaces--;
		for (int j = 0; j <= i; j++)
		{
			// printf("*");
			printf("%d ", combinations(i, j));
		}
		printf("\n");
	}
}

void get_rows(int* rows)
{
	printf("Enter the number of rows: ");
	scanf(" %d", rows);
}

int main()
{
	int rows;
	get_rows(&rows);
	// printf(" %d\n", factorial(3));
	// printf(" %d\n", combinations(1,1));
	pascals(rows);
	return 0;
}