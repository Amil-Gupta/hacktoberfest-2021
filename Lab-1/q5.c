#include<stdio.h>
#include<stdlib.h>

int num_non_zero(int **a, int n) //Counts the number of non-zero elements in the matrix
{
    int i, j, count=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if( a[i][j] != 0 )
            {
                count++;
            }
        }
    }
    return count;
}

int find_sum_above_leading(int **a, int n) //Finds the sum of the elements above the leading diagonal
{
    int i, j, sum=0;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            sum += a[i][j];
        }
    }

    return sum;
}

void display_elements_below_minor(int **a, int n) //Displays the elements below the minor diagonal
{
    int i, j;
    for(i=1; i<n; i++)
    {
        for(j=n-i; j<n; j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    printf("\n");
}

int find_product_of_diagonals(int **a, int n) //Finds the product of diagonal elements
{
    int i, prod=1;
    for(i=0; i<n; i++)
    {
        prod *= a[i][i];
        if( (i != (n/2)) || (n%2==0) ) //The diagonals will intersect if n is odd,
                                        // in which case we avoid multiplying the intersecting element twice
        {
            prod *= a[i][n-i-1];
        }
    }
    return prod;
}

int main()
{
    int n, i , j;
    printf("Enter the size of the square matrix\n");
    scanf("%d", &n);
    int **a = (int**) malloc( sizeof(int*) * n );

    printf("Enter matrix elements\n");
    for(i=0; i<n; i++)
    {
        a[i] = (int*) malloc( sizeof(int) * n );
        for(j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Number of non-zero elements = %d\n\n", num_non_zero(a, n));
    printf("Sum of elements above leading diagonal = %d\n\n", find_sum_above_leading(a, n));
    printf("Elements below the minor diagonal are:\n");
    display_elements_below_minor(a, n);
    printf("Product of diagonal elements (leading and minor) = %d\n", find_product_of_diagonals(a, n));

    return 0;
}