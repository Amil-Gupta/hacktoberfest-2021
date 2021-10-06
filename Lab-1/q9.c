#include<stdio.h>

int main()
{
    int n, i;
    printf("Enter a number\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        if((i * i <= n) && ((i+1) * (i+1) > n)) // Can also use (n/i == i), but that will use the limitations of
                                                // int datatype instead of logic
        {
            printf("isqrt(%d) = %d\n", n ,i);
        }
    }

    return 0;
}