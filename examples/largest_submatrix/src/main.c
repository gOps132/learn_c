#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

void create_matrix(int rows, int cols, int arr[rows][cols])
{
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

// create a function that checks specific bound 
// of the matrix 
// void check_bounded_matrix(int rs, int re, int cs, int ce, int cols, int *arr[cols])

int largest_submatrix_eq_elem(int rows, int cols, int arr[rows][cols])
{
    int result = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // define inner checkable bounds
            int k,l;
            for (k = i; k < rows; k++)
            {
                for (l = j; l < cols; l++)
                {
                    // check if submatrix is valid
                    int flag = 1;
                    for (int p=i; p <= k; p++)
                    {
                        for (int q=j; q <= l; q++)
                        {
                            if (arr[p][q] != arr[i][j])
                            {
                                flag = 0;
                                break;
                            }
                        }
                        // stop checking, current bounded matrix is invalid
                        if (flag == 0)
                            break;
                    }
                    // update results with the max 
                    if (flag == 1)
                        result = MAX(result, (k-i+1)*(l-j+1));
                }
            }
        }
    }
    return result;
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    create_matrix(rows, cols, arr);
    printf("The largest submatrix with equal elements has size %d", largest_submatrix_eq_elem(rows, cols, arr));
    return 0;
}
