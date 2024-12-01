#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_BUFFER 100

int check_palindrome(char *str)
{
    for(int i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        if(str[i]!=str[j])
            return 0;
    }
    return 1;
}

int main(){
    char str[MAX_CHAR_BUFFER];
    printf("Enter word: ");
    scanf(" %s", str);
    char *str2;
    for(int i = 0; i < strlen(str); i++)
    {
        str2[i] = tolower(str[i]);
    }
    if (!check_palindrome(str2))
    {
        printf("%s is not a palindrome.\n", str);
        return 1;
    }
    printf("%s is a palindrome.\n", str);
    return 0;
}