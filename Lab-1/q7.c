#include<stdio.h>

int main()
{
    int n, i, temp;
    
    // Input the array
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    //Swap pairs of elements
    for(i=1; i<n; i += 2)
    {
        temp = a[i];
        a[i] = a[i-1];
        a[i-1] = temp;
    }

    //Display the array
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}