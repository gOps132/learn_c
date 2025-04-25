#include <stdio.h>
#include <stdlib.h>

typedef enum Months {
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    June,
    Jul,
    Aug,
    Sep,
    Nov,
    Dec
} Months;

char* get_month(int no)
{
    switch(no) 
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }
}

int main(){
    int n;
    printf("Enter a number (1-12): ");    
    scanf("%d", &n);
    if (n < 1 && n > 12)
        return EXIT_FAILURE;
    printf("You have selected the month of %s", get_month(n)); 

    return EXIT_SUCCESS;
}
