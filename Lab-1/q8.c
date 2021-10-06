#include<stdio.h>

int main()
{
    int n,p;

    // Input the array
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    p = 1;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        p *= a[i];
    }

    // Find output array
    for(int i=0; i<n; i++)
    {
        a[i] = p / a[i];
    }

    // Print output array
    for(int i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}
