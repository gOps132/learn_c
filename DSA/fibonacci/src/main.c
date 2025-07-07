#include <stdio.h>

/**
 * Pure recursive approach, most basic form
 * time complexity: O(2^n)
 * space complexity: O(n) due to the call stack
 * 
 * For each recursive call, an activation record (function call frame) 
 * is pushed onto the call stack. Once the recursion unwinds, the stack frames are popped.
 * Therefore, the space complexity is proportional to the depth of the recursive call stack, 
 * which is O(n).
*/
unsigned long int recursive_fibonacci(unsigned long int n)
{
    if(n <= 1)
        return n;

    return recursive_fibonacci(n-1)+recursive_fibonacci(n-2);
}

/**
 * Dynamic programming
 * Memoization
 * time complexity: O(n)
 * space complexity: O(n)
*/
unsigned long int memo_fibonacci(unsigned long int n, unsigned long int *memo)
{
    if(memo[n] > 0)
        return memo[n];

    if(n <= 1)
        return n;

    return memo_fibonacci(n-1, memo)+memo_fibonacci(n-2, memo);
}

/**
 * Dynamic Programmming
 * Iterative Approach
 * time complexity: O(n)
 * space complexity: O(1) as it only uses a few variables instead of an array.
*/
unsigned long int iterative_fibonacci(unsigned long int n)
{
    if (n <= 1)
        return n;
    
    unsigned long int a = 0, b = 1, temp;
    for (unsigned long i = 2; i <= n; i++)
    {
        temp = a+b;
        a = b;
        b = temp;
    }
    return b;
}

/**
 * Matrix Exponentiation
 * time complexity: O(log(n))
 * space complexity: O(1) or O(log(n)) if using recursion for
 * exponentiation
*/
void multiply(unsigned long int F[2][2], unsigned long int M[2][2])
{
    unsigned long int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    unsigned long int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    unsigned long int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    unsigned long int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(unsigned long int F[2][2], unsigned long int n)
{
    if (n == 0 || n == 1)
        return;
        
    unsigned long int M[2][2] = {{1, 1}, {1, 0}};
    
    power(F, n / 2);
    multiply(F, F);
    
    if (n % 2 != 0)
        multiply(F, M);
}
unsigned long int matrix_e_fibonacci(unsigned long int n)
{
    unsigned long int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

int main()
{
    unsigned long int i;
    // unsigned long int memo[100] = {0};
    printf("Enter fibonacci: ");
    scanf(" %lld", &i);
    for(int y = 0; y <= i; y++)
    {
        printf("%d.) %llu\n",y, matrix_e_fibonacci(y));   
        if (y == 10001)
            printf("overflow here\n");
    }
    return 1;
}
