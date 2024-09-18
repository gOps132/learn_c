#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 100

// bitmask
#define TOGGLE_BIT(x, pos) x | (1U << pos)

// isupper(), islower(), isdigit()

// example on bitwise operations
// make a password checker
// input sifhsufh
// your password needs to have a capital letter, small letter and digit
// password is correct

// declaring bitmasks
#define FLAG1 TOGGLE_BIT(1, 0) // 0001 
#define FLAG2 TOGGLE_BIT(1, 1) // 0010
#define FLAG3 TOGGLE_BIT(1, 2) // 0100

// int 4 bytes 16 bits 0000
// flag 1 << 0 0001
//  0 1 = 1
// 0 0 = 0
// 0111

int main(int argc, char** argv)
{
    int flags = 0;
    int combined = FLAG1 | FLAG2 | FLAG3;

    char pass[MAX_BUFFER];
    printf("Enter password: ");
    scanf("%s",&pass);
    // printf("your password is: %s\n",pass);

    for (int i=0;i < strlen(pass);i++)
    {
        // printf("%c",pass[i]);
        if (isupper(pass[i])){
            flags |= FLAG1;
        }
        if (islower(pass[i])){
            flags |= FLAG2;
        }
        if (isdigit(pass[i])){
            flags |= FLAG3;
        }
    }

    if((flags & combined) == combined) {
        printf("your password is valid.\n");
    }
    else {
        printf("your passwords needs to have a capital, lower and a single digit to be valid.\n");
    }

    return 0;
}
