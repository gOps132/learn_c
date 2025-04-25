#include <stdio.h>

void remove_duplicates(int *arr, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            if (arr[i]==arr[j] && i != j)
            {
                // delete element and shift values to left
                for (int k = j; k < *n; k++)
                {
                    arr[k] = arr[k+1];
                }
                (*n)--;
            }
        }
    }
}

void display_elements(int *arr, int n)
{
    printf("Unique Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0;  i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    remove_duplicates(arr, &n);
    display_elements(arr, n);
    
    return 0;
}
