#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", (arr+i));
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(arr+i));
    }
    
    
}
