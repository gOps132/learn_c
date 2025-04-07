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

void display_fancifully(int *arr, int n, int c, int w)
{
    for (int i = 0; i < n; i++)
    {
        if (i == c)
        {
            printf(BACKGROUND_TEXT_COLOR(21, 22, " %d "), arr[i]);
        } else if ( i == w )
        {
            printf(BACKGROUND_TEXT_COLOR(20, 196, " %d "), arr[i]);
        } else
        {
            printf(BACKGROUND_TEXT_COLOR(16, 30, " %d "), arr[i]);
        }
    }
}

int main(){
    int arr[] = { 52,2,30,21,62,10,43,25 };
   
    printf("initial:\n");
    int n = sizeof(arr) / sizeof(int);
    display(arr,n); 
    printf("\n");  
    int i, j;
    for (i = 1; i < n; i++)
    {
        int key = arr[i], j = i -1;
        while (j >= 0 && arr[j] > key)
        {        
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

        display_fancifully(arr, n, i, j); 

        printf("pass %d\n", i+1);
        SLEEP(500); 

    }
    
    return 0;
}
