
#include <stdio.h>
#include <string.h>

#define MAX_CHAR_BUFFER 100

int main(){
    const char seperating_char[] = ",.;!?";
    char foo[MAX_CHAR_BUFFER];
    char *s;
    printf("Enter string: ");
    fgets(foo, MAX_CHAR_BUFFER, stdin);
    foo[strlen(foo)-1] = '\0';
    int n;

    for (s = foo; *s != 0; /*empty*/) {
        /* Get the number of token separator characters. */
        n = (int)strspn(s, seperating_char);
        if (n > 0)
            printf("skipping separators: << %.*s >> (length=%d)\n", n, s, n);
        /* Actually skip the separators now. */
        s += n;
        /* Get the number of token (non-separator) characters. */
        n = (int)strcspn(s, seperating_char);
        if (n > 0)
            printf("token found: << %.*s >> (length=%d)\n", n, s, n);
        /* Skip the token now. */
        s += n;
    }
    printf("== token list exhausted ==\n"); return 0;

    return 0;
}