#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100

int main(int argc, char** argv) 
{
    char str[BUF_SIZE];
    printf("Enter string: ");
    scanf("%[^\n]", str);
    
    const char sep_chars[] = ",.;!? ";
    char *current;
    int n;
    
    for (current = str; *current != 0; /**/)
    {
        n = (int)strspn(current, sep_chars);
        
        if (n > 0)
        {
            // %.*s specifies number of characters to print from string
            printf("Skipping seperators: << %.*s >> (length=%d)\n", n, current, n);
        }
        
        current += n; // skip the number of characters

        // get the number of token non seperator characters
        n = (int)strcspn(current, sep_chars);

        if (n > 0)
            printf("token found: << %.*s >> (length=%d)\n", n, current, n);

        current += n;
    }

    printf("Token list exhausted\n");

    return EXIT_SUCCESS;
}
