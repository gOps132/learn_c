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

int main(){
    int arr[] = { 23,78,45,8,32,56 };

    printf("initial:\n");
    int n = sizeof(arr) / sizeof(int);
    display(arr,n); 
    printf("\n");  
    int i, j;

    for (i = 0; i < n-1; i++)
    {
    int min = i;

        for (j = i+1; j < n; j++)
        {        
            if (*(arr+j) < *(arr+min)) 
                min = j;
        }

        int tmp = *(arr+min);
        *(arr+min) = *(arr+i);
        *(arr+i) = tmp;

        display_fancifully(arr, n, i, j); 

        printf("pass %d\n", i+1);
        SLEEP(500); 

    }

    return 0;
}
