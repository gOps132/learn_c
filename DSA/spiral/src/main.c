#include <stdio.h>
 
void spiral(int row, int col, int arr[row][col])
{
    int cnt = 1;
    int final = row*col;
    int persist_row = row;
    int persist_col = col;
    int i = 0, j = 0;
    for(;;col--&&row--)
    {
        if (cnt == final)
        {
            arr[i][j] = cnt;
            break;
        }
        for (; j < row - 1; j++)
        { 
            // if (cnt == final)
            //     break;
            arr[i][j] = cnt;
            printf("1: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        }
        for (; i < col - 1; i++)
        { 
            // if (cnt == final)
            //     break;
            arr[i][j] = cnt;
            printf("2: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        } 
        for (; j > persist_row - row;j--)
        {
            // if (cnt == final)
            //     break;
            arr[i][j] = cnt; 
            printf("3: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        };
        for (; i > persist_col - col + 1; i--)
        {  
            // if (cnt == final)
            //     break;
            arr[i][j] = cnt;
            printf("4: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        };
    }
}

void spiral_two(int row, int col, int arr[row][col])
{
    int cnt = 1;
    int final = row*col;
    int persist_row = row;
    int persist_col = col;
    int i = 0, j = 0;
    for(;;col--&&row--)
    {
        if (cnt == final)
        {
            arr[i][j] = cnt;
            break;
        }
        for (; j <= row - 1; j++)
        { 
            if (cnt == final)
                break;
            arr[i][j] = cnt;
            printf("1: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        }
        for (; i <= col - 1; i++)
        { 
            if (cnt == final)
                break;
            arr[i][j] = cnt;
            printf("2: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        } 
        for (; j > persist_row - row;j--)
        {
            if (cnt == final)
                break;
            arr[i][j] = cnt; 
            printf("3: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        };
        for (; i > persist_col - col + 1; i--)
        {  
            if (cnt == final)
                break;
            arr[i][j] = cnt;
            printf("4: %d [%d][%d]\n", cnt, i, j);
            cnt++;
        };
    }
}


void display(int row, int col, int arr[row][col])
{
    for (int i = 0; i < row; i++)
    { 
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
 
int main(){
    int r = 1, c = 3;
    printf("Enter number of columns: ");
    scanf("%d", &c);
    printf("Enter number of rows: ");
    scanf("%d", &r);
    int arr[r][c];
    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            arr[i][j] = 0;
        }
    }
 
    spiral(r, c, arr);
    // spiral_two(r, c, arr);
    display(r, c, arr);
}