#include<stdio.h>
#include<math.h>

int integer_square_root(int n)
{
    int i;
    for(i=1; i<=n; i++) //Positive integers begin from 1
    {
        if((float)n / i <= i) //this will return the first number whose square is greater than n, i.e. ceil(root(n))
        {
            return i;
        }
    }

    return 0; //possible only when n is 0 or negative, i.e. not a positive integer
}

int main()
{
    int n, sqrt;
    printf("Enter a number\n");
    scanf("%d", &n);
    sqrt = integer_square_root(n);

    if(sqrt)
    {
        printf("Integer square root(ceiling) = %d\n", sqrt);
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}