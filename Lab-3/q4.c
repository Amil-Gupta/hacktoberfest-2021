#include<stdio.h>

int find_max_sum(int *a, int n)
{
    int i, j, S=0, sum=0;
    for(i=0; i<n; i++)
    {
        sum=0;
        for(j=i; j<n; j++)
        {
            sum += a[j];
            if(sum > S)
            {
                S = sum;
            }
        }
    }
    return S;
}

int main()
{
    int n, i;
    printf("Enter no. of elements\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Maximum subarray sum(S) = %d\n", find_max_sum(a, n));

    return 0;
}