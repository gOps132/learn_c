#include <stdio.h>

/**
 * Determine if matrix contains a saddle point (least in row, greatest in column)
 */
int main(){
    int row,col;
    printf("Enter the size of the array (row, col): ");
    scanf("%d %d",&row, &col);
    int arr[row][col]; // row, col
    // INPUT MATRIX
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // check least in row
    for (int i = 0; i < row; i++)
    {
        int row_max = arr[i][0]; // maximum element
        int col_index = 0;
        // find the maximum element in the current row and column index
        for (int j = 1; j < col; j++)
        {
            if (arr[i][j] > row_max) 
            {
                col_index = j;
                row_max = arr[i][j];
            }
        }
        int is_saddle = 0;
        // check if col_index is the least in its column
        for (int j = 0; j < row; j++)
        {
            int col_maximum = arr[i][col_index];
            if (row_max < arr[j][col_index])
            {
                is_saddle = 1;
                break;
            }
        }
        if (is_saddle)
        {
            printf("SADDLE POINT PRESENT");
            return 0;
        }
    }
    printf("NO SADDLE POINT PRESENT");

    return 0;
}
