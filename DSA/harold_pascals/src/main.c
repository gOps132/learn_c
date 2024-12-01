#include <stdio.h>

int main(){
	int numRows, row, col, value;

	printf("Enter number of rows: ");
	scanf("%d", &numRows);

	for (row = 0; row < numRows; row++){
		value = 1;
		for (col = 0; col <= row; col++){
			printf("%d ", value);
			value *= (row - col)/(col + 1);
		}
		printf("\n");
	}
}