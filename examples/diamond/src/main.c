#include <stdio.h>

void print_diamond(int rows)
{
    int i = 0, j = 0;
    // generate reverse staircase
    while(i < rows)
    {
        j = rows-1;
        while (j >= i)
        {
            printf(" "); // test
            j--;
        }
        j = 0;
        while (j < ((i+1)*2)-1)
        {
            printf("*"); // test
            j++;
        }
        printf("\n");
        i++;
    }
    i = rows - 2;
    // generate ascending stairsd
    while (-1 < i)
    {
        j = rows-1;
        while(j >= i)
        {
            printf(" ");
            j--;
        }
        j = ((i+1)*2)-2;
        while(j >= 0)
        {
            printf("*");
            j--;
        }
        printf("\n");
        i--;
    }
}

void get_input(int *row)
{
    printf("Enter the number of rows: ");
    scanf(" %d", row);
}

int main(){
    int rows;
    get_input(&rows);
    print_diamond(rows);
    return 0;
}
