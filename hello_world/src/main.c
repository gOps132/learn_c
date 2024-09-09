#include <stdio.h>

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

int main() {
    int decimal;

back:
    printf("Enter a decimal number: ");
    scanf(" %d", &decimal);

    printf("Binary representation: ");
    if (decimal == 0) {
        printf("0");
        printf("\n");
    } else {
        printBinary(decimal);
        printf("\n");
    }
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
