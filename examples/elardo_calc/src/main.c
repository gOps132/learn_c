#include <stdio.h>

int main()
{
    int interrupt = 1;
    while(interrupt) {
        int select_option;
        printf("Select Option:\n1. (+)\n2. (-)\n3. (*)\n4. (/)\n");
        scanf(" %d", &select_option);
        double result, input1, input2;
        printf("Enter first input: ");
        scanf(" %lf", &input1);
        printf("Enter second input: ");
        scanf(" %lf", &input2);
        switch(select_option) {
            case 1: {
                result = input1 + input2;
                break;
            }
            case 2: {
                result = input1 - input2;
                break;
            }
            case 3: {
                result = input1 * input2;
                break;
            }
            case 4: {
                result = input1 / input2;
                break;
            }
            default: {
                interrupt = 0;
                break;
            }
        }
        printf("Result: %.2lf\n", result);
    }
    return 1;
}