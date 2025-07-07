#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CHAR_BUFFER 100

int check_str_palindrome(char *str)
{
    for(int i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        if(str[i]!=str[j])
            return 0;
    }
    return 1;
}

int check_num_palindrome(int num)
{
    if (num < 0) return 0; // negative numbers are not palindromes
    int n = (int)log10(num) + 1; // 12321 = 6
    
    int left = num;
    for (int i = 0; i < n / 2; i++)
    {
        int left_digit = left / (int)pow(10, n-i-1) % 10;
        int right_digit = (num / (int)pow(10, i)) % 10;

        if (left_digit != right_digit)
            return 0;
    }
    return 1;
}

int main(){
    char str[MAX_CHAR_BUFFER];
    /*printf("Enter word: ");*/
    /*scanf(" %s", str);*/
    /*char *str2;*/
    /*for(int i = 0; i < strlen(str); i++)*/
    /*{*/
        /*str2[i] = tolower(str[i]);*/
    /*}*/
    
    /*if (!check_str_palindrome(str2))*/
    /*{*/
        /*printf("%s is not a palindrome.\n", str);*/
        /*return 1;*/
    /*}*/

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (!check_num_palindrome(n))
    {
        printf("%d is not a palindrome.\n", n);
        return 1;
    }
    printf("%d is a palindrome.\n", n);
    return 0;
}
