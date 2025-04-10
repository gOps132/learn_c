/**
 * sort absolute difference K between values
 */
#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]); 
    }
}

void sort_absolute_diff(int *arr, int n, int k)
{
    int tmp[n];
    for (int i = 0; i < n; i++)
        tmp[i] = abs(arr[i] - k); 

    int i, j;
    // use selection sort
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {        

            if (tmp[j] > tmp[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                temp = tmp[j];
                tmp[j] = tmp[j+1];
                tmp[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int k;
    printf("Enter K: ");    
    scanf("%d", &k);
    printf("Before: ");
    display(arr, n);
    
    sort_absolute_diff(arr, n, k); 

    printf("\nAfter: ");
    display(arr, n);
    
    return 0;
}
