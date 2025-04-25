#include <stdio.h>
#include <math.h>

// function to check if a number is prime
int check_prime(int n)
{
    if (n<=1) return 0;
    int limit = (int)sqrt(n);
    for (int i = 2; i <= limit; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (check_prime(n))
    {
        printf("%d is a prime.", n);
    } else {
        printf("%d is not a prime.", n);
    }
    return 0;
}
