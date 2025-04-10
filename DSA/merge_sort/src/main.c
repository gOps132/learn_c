#include <stdio.h>
#include "color.h"
#include "sleep.h"


// TODO: make a sorting visualizer using color.h, modify
// the current w as the background, refresh the line every single change of the
// walk mark each w and the current element as different background colors

void display(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]); 
    }
}

void display_fancifully(int *arr, int s, int n, int c, int w)
{
    for (int i = s; i < n; i++)
    {
        if (i == c)
        {
            printf(BACKGROUND_TEXT_COLOR(5, 18, " %d "), arr[i]);
        } else if ( i == w )
        {
            printf(BACKGROUND_TEXT_COLOR(10, 196, " %d "), arr[i]);
        } else
        {
            printf(BACKGROUND_TEXT_COLOR(16, 30, " %d "), arr[i]);
        }
    }
}

int merge(int arr[], int l, int m, int h)
{
    int arr1[10], arr2[10];
    int n1, n2, i, j, k;
    n1 = m-l+1;
    n2 = h-m;
    
    for (i = 0; i < n1; i++)
        arr1[i] = arr[l+i];
    for (j = 0; j < n2; j++)
        arr2[j] = arr[m+j];

    arr1[i] = 9999;
    arr2[j] = 9999;

    i = 0;
    j = 0;

    for (k = l; k <= h; k++)
    {
        if (arr1[i] <= arr2[j])
            arr[k] = arr1[i++];
        else
            arr[k] = arr2[j++];
    }

    return 0;
}

int merge_sort(int arr[],int low,int high)
{
    int mid;
    if(low<high) {
        mid=(low+high)/2;
        // Divide and Conquer
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        // Combine
        merge(arr,low,mid,high);
    }
    return 0;
}

int main(){
    int arr[] = { 52,2,30,21,62,10,43,25 };
   
    printf("initial:\n");
    int n = sizeof(arr) / sizeof(int);
    display(arr,n); 
    printf("\n");  

    merge_sort(arr, 1, n);
    display(arr, n);
   
    return 0;
}
