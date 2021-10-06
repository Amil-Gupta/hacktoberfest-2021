#include<stdio.h>

int main()
{
    int n, i, s, l;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("Array:\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d\t",a[i]);
    }

    printf("\n");

    s=l=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i] < s)
        {
            s=a[i];
        }
        else if(a[i] > l)
        {
            l=a[i];
        }
    }

    printf("Smallest number = %d \nLargest number = %d\n", s, l);

    return 0;
}