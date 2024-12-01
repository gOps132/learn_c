#include <stdio.h>

/**
 * matrix must be the same size
*/
void m4_add(float a[4][4], float b[4][4], float c[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void m4_multiply(float a[4][4], float b[4][4], float c[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            c[i][j] = a[i][j] * b[j][i];
        }
    }
}

void v4m4_multiply(float v[4], float m[4][4], float vout[4])
{
    for(int x = 0; x < 4; x++)
    {
        vout[x] = 0.0f;
        for(int i = 0; i < 4; i++)
        {
            vout[x] += m[x][i] * v[i];
        }
    }
}

void v4m4_translate()
{
    
}

void m4_print(float a[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        printf("\t");
        for(int j = 0; j < 4; j++)
        {
            printf(" %.2f ", a[i][j]);
        }
        printf("\n");
    }
}

void v_print(float *v, int n)
{
    printf("\t");
    for(int x = 0; x < n; x++)
    {
        printf(" %.2f ", v[x]);
    }
}

int main()
{
    float av[4] = { 1.0f, 2.0f, 3.0f, 4.0f };

    float a[4][4] =  {  { 1.0f, 0.0f, 0.0f, 0.0f },
                        { 0.0f, 1.0f, 0.0f, 0.0f },
                        { 0.0f, 0.0f, 1.0f, 0.0f },
                        { 0.0f, 0.0f, 0.0f, 1.0f }  };

    float b[4][4] =  {  { 0.0f,  1.0f,  2.0f,  3.0f }, 
                        { 4.0f,  5.0f,  6.0f,  7.0f }, 
                        { 8.0f,  9.0f,  10.0f, 11.0f }, 
                        { 12.0f, 13.0f, 14.0f, 15.0f }  };

    float c[4][4] =  {0};
    float cv[4] =  {0};

    // m4_add(&a, &b, &c);
    m4_multiply(&a, &b, &c);

    v4m4_multiply(&av, &a, cv);

    printf("Resultant matrix:\n");
    m4_print(&c);

    printf("Resultant vector: \n");
    v_print(&cv, 4);
    printf("\n");

    return 0;
}