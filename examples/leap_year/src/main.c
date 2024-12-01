/**
 * LEAP YEAR PROBLEM
 * WINZIEEE 
 * INSTRUCTIONS: EVERY LEAP YEAR IS DIVISIBLE BY 4.
 * HOWEVER IF A YEAR IS DIVISIBLE 100 IT MUST ALSO BE DIVISIBLE BY 400 
 * FOR IT TO BE A LEAP YEAR, HENCE 2000 IS A LEAP YEAR, BUT 1900 IS NOT.
 * MAKE A PROGRAM THAT WILL INPUT A VALUE FOR YEAR AND OUTPUT WHETHER IT
 * IS A "LEAP YEAR" OR "NOT A LEAP YEAR"
*/
#include <stdio.h>

int main (){
    int year; // address &year

    printf("Enter the leap year: ");
    scanf(" %d", &year);
    if(year % 4 == 0 || (year % 100 != 0 && year % 400 == 0))
    {
        printf("Leap year");
    } else
    {
        printf("Not a Leap year");
    }

    // if its divisible by 400
    // if(year % 400 == 0) // if true execute code if not skip this
    // {
    //     printf("Leap year");
    //     return 1;
    // }
    // if(year % 100 == 0)
    // {
    //     printf("Not a Leap Year");
    //     return 1;
    // }
    // if(year % 4 == 0)
    // {
    //     printf("Leap Year");
    //     return 1;
    // }
    // printf("Not leap year");
}