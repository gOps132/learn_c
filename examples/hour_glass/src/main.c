#include <stdio.h>

void hour_glass(int n)
{
    // n-2
    for (int i = 1; i <= n; i++)
    {
        for (int space = 1; space <= i - 1; space++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2*(n-i)+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i < n; i++)
    {
        for(int space = 1; space < n - i; space++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1;  j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void get_input(int *n)
{
    printf("Enter a number: ");
    scanf(" %d", n);
}

int main()
{
    int n;
    get_input(&n);
    hour_glass(n);

    return 0;
}