#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void round_square_matrix(float **a, int **b, int n)
{
    int i, j;
    float rval;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            b[i][j] = round(a[i][j]);
        }
    }
}

int main()
{
    int n, i, j;
    printf("Enter size of square matrix\n");
    scanf("%d", &n);
    float **a = (float**) malloc(n * sizeof(float*));
    for(i=0; i<n; i++)
    {
        a[i] = (float*) malloc(n * sizeof(float));
    }
    int **b = (int**) malloc(n * sizeof(int*));
    for(i=0; i<n; i++)
    {
        b[i] = (int*) malloc(n * sizeof(int));
    }

    printf("Enter matrix elements\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    round_square_matrix(a, b, n);

    printf("Rounded square matrix is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}