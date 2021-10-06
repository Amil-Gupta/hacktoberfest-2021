#include<stdio.h>

int main()
{
    int n, i, p;

    // Input the array
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Find output array
    p = 1;
    for(i=0; i<n; i++)
    {
        p *= a[i];
    }
    for(i=0; i<n; i++)
    {
        a[i] = p / a[i];
    }

    // Print output array
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}