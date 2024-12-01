#include <stdio.h>

void get_input(int *n)
{
    printf("Enter number of rows: ");
    scanf(" %d", n);
}

void butterfly(int n)
{
    int spaces = (2 * n) - 2;
    for (int i = 1; i <= n; i++)
    {
        // print spaces
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
        spaces -= 2;
    }
    spaces = 0;
    for (int i = n; i > 0; i--)
    {
        // 
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }    
        printf("\n");
        spaces+=2;
    }
}

int main()
{
    int n;
    get_input(&n);
    butterfly(n);

    return 0;
}