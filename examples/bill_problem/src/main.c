/**
 * Any customer whose total purchase IS AT LEAST P1000 will given
 * 10% discount. Make a program that would input the customer's PURCHASE and 
 * output his net BILL.
*/

/*
#include <stdio.h>

int main() {
    int bill;
    printf("Enter purchase amount:");
    scanf("%d", &bill);
    if (bill >= 1000) 
    {
        bill = bill * 0.90;
    } else
    {
        bill = bill;
    }
    printf("Your Bill is %d", bill);
}
*/
#include <stdio.h>

int main(){
    int purchase;

    printf("Enter the purchase: ");
    scanf("%d", &purchase);

    if(purchase >= 1000)
    {
        purchase = purchase * 0.9;
    }

    printf("Bill: %d", purchase);

}