#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR_BUFFER 100

void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);  // Recursive call to print higher order bits
    }
    printf("%d", n % 2);  // Print the current bit
}

void printOctal(int n) {
    if (n > 1) {
        int quotient = n / 8;
        // printf("quotient: %d\n", quot);
        printOctal(quotient);  // Recursive call to print higher order bits
    }
    // printf("%d\n", n);
    printf("%d", n % 8);  // Print the current bit
}

void printHexadecimal(int decimal) {
    char hex[32];  // Array to store hexadecimal digits
    int i = 0;

    // Handle the special case where the number is 0
    if (decimal == 0) {
        printf("0");
        return;
    }

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;

        // Store the appropriate character ('0'-'9', 'A'-'F')
        if (remainder < 10)
            hex[i] = remainder + '0';
        else
            hex[i] = remainder - 10 + 'A';

        decimal = decimal / 16;
        i++;
    }

    // Print the hexadecimal number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

// int binary_to_decimal(char* binary) {
//     int d = 0;
//     for(size_t i = strlen(binary); i > 0; i--)
//     {
//         int t = (binary[i] == 48 ? 0 : 1);
//         d += (int)pow(2, i-1);
//     }
//     return d;
// }

char input[MAX_CHAR_BUFFER];
int decimal;

int main() {
back:
    // printf("Enter a decimal number: ");
    // scanf(" %d", &decimal);

    // printf("Binary representation: ");
    // if (decimal == 0) {
    //     printf("0");
    //     printf("\n");
    // } else {
    //     printBinary(decimal);
    //     printf("\n");
    // }

    printf("Enter a binary number: ");
    scanf(" %s", &input);
    getchar();

    printf("Decimal: %d\n",binary_to_decimal(input));

    goto back;

    // printf("Octal representation: ");
    // if (decimal == 0) {
    //     printf("0");
    // } else {
    //     printOctal(decimal);
    // }

    // printf("Hexadecimal representation: ");
    // if (decimal == 0) {
    //     printf("0");
    // } else {
    //     printHexadecimal(decimal);
    // }

    // printf("Hexadecimal representation: ");
    // if (decimal == 0) {
    //     printf("0");
    // } else {
    //     printf("%x", decimal);
    // }

    printf("\n");

    return 0;
}
