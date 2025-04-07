#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    // sqrt is the std dev
double std_dev(int *arr, int n)
{
    char config = 'P';

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    double mean = (double)sum / (double)n;

    // variance
    double sqrdif = 0.0;

    for (int i = 0; i < n; i++)
    {
        sqrdif += pow((arr[i]-mean), 2);
    }
    // if sample then size - 1
    if (config == 'P')
    {
        sqrdif /= (double)n;
    } else if (config == 'S')
    {
        sqrdif /= (double)(n-1);
    }


    return sqrt(sqrdif);
}

int main(){
    int n;
    printf("Input size of the array: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    double res = std_dev(arr, n);
    printf("Std deviation = %.2lf", res);
    return 0;
}
