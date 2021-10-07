#include<stdio.h>//Importing the header file for standard input and output operations.

int find_max_sum(int *a, int n)//The find_max_sum function to find the max values which takes 2 parameters.
{
    int i, j, S=0, sum=0;
    for(i=0; i<n; i++)
    {
        sum=0;//initializing the sum variable.
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
    scanf("%d", &n);//Accepting array size in the variable n.
    int a[n];
    printf("Enter array elements\n");
    //Accepting element of array.
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Maximum subarray sum(S) = %d\n", find_max_sum(a, n));//Printing the Maximum subarray sum(s).

    return 0;
}
