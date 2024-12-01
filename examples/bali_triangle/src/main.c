#include <stdio.h>

void get_input(int *n)
{
    printf("Enter number of rows: ");
    scanf(" %d", n);
}

/*
void triangle(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        // spaces
        for (int j = rows; j > i; j--)
        {
            printf(" ");
        }
        // first set of increasing numbers
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        for (int j = i-1; j >= 1; j--)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}
*/

void triangle(int n)
{
    for(int i = 0; i < n; i++){
        for(int j = n-2 ; j >=i;j--){
            printf(" ");
        }
        for(int k = 1;k<=(2*i) + 1; k++){
            if(k>i+1){
                printf("%d",k-((k-(i+1))*2));
            }else{
                printf("%d",k);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n = 6;
    get_input(&n);
    triangle(n);

    return 0;
}