/**
 * 6 matchsticks 1 house, 16 matchsticks 3 houses
 * bill problem
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR_BUFFER 100


int main(){
    int i;
    printf("Enter how many houses: ");
    scanf(" %d", &i);
    printf("The total matches %d", (6*i)-(i-1));
    return 0;
}


// int main()
// {
//     int value[9] = {1000,500,200,100,50,20,10,5,1};
//     int bill_count[9] = {0};
//     int cash;
//     printf("How much: ");
//     scanf(" %d", &cash);
//     for(int i = 0; i < 9;)
//     {
//         if(cash >= value[i])
//         {
//             cash -= value[i]; 
//             bill_count[i]++;
//         } else {
//             i++;
//         }
//     }
//     for(int i = 0; i < 9; i++)
//     {
//         printf("%d:\t%d\n", value[i], bill_count[i]);
//     }
//     return 0;
// }