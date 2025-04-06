#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_BUFFER 100

void get_unique_elements(char *str1, char *str2, char *output)
{
    int len, i, j = 0;
    len = strlen(str1);
    if (len > 0 && str1[len - 1] == '\n') {
        str1[len - 1] = '\0';
    }
    strcat(str1,str2);

    len = strlen(str1);
    if (len <= 1)
    {
        strcpy(output, str1);
        return;
    }

    char tmp[len+1];
    for (i = 0; i < len; i++)
    {
        int found_duplicate = 0;
        for (int k = 0; k < j; k++)
        {
            // check if value exists in tmp array
            if (str1[i] == tmp[k])
            {
                found_duplicate = 1;
                break;
            }
        }
        if (!found_duplicate)
        {
            tmp[j++] = str1[i];
        }
    }
    tmp[j] = '\0';

    strcpy(output, tmp);
}

int main() 
{
    char str1[MAX_CHAR_BUFFER], str2[MAX_CHAR_BUFFER], output[MAX_CHAR_BUFFER];

    printf("Enter first string: ");
    fgets(str1, MAX_CHAR_BUFFER, stdin);

    printf("Enter second string: ");
    fgets(str2, MAX_CHAR_BUFFER, stdin);

    get_unique_elements(str1, str2, output);
   
    printf("%s", output);
    return 0;
}
