//Number of multiplications made in divide and conquer algorithm will be less than that in brute force algorithm
//This is because in D&C, we will multiply powers of a to get to the next power (approx. log n multiplications)
//But in brute force method, we multiply with 'a' every time (n-1 multiplications)

#include<stdio.h>

int expo_dc(int a, int n) //Calculates a^n by divide and conquer method
{
    int half_pow = n/2;
    
    if(n==1) //As n is a positive integer, its minimum value is 1. It will not take lower value during recursion either
    {
        return a;
    }
    else
    {
        return (expo_dc(a, half_pow) * expo_dc(a, (n - half_pow)));
    }
}

// int expo_bf(int a, int n) //Calculates a^n by brute force method (written for reference)
// {
//     int i, pow = a; //Minimum value of n=1, so minimum value of pow=a
//     for(i=1; i<n; i++)
//     {
//         pow *= a;
//     }
//     return pow;
// }

int main()
{
    int a, n;
    printf("Enter a<space>n\n");
    scanf("%d%d", &a, &n);
    printf("a^n = %d\n", expo_dc(a, n));

    return 0;
}