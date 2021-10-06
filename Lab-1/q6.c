//Approaches and strategies I could think of:

//1. Sort the array(lets say in ascending order), find the first value that is not equal to a[0] 
//while traversing forward from the start and the first value that is not equal to a[n-1] while traversing backwards
//from the end. These are the second smallest and second largest element respectively.
//If one of the values is found, we know that the other will exist as well. So, we check for it and print the
//results accordingly.

//2. THE ONE THAT I AM USING IN THIS PROGRAM. Take four variables, for finding the smallest, largest, second smallest
//and second largest elements. Traverse once through the array and keep updating the values of these variables
//as necessary. Check for the existence of the required values as mentioned in method 1 and print the results
//accordingly.

#include<stdio.h>

void insert_random_within_range(int *a, int n, int l, int u)
{
    int i;
    for(i=0; i<n; i++)
    {
        a[i] = (rand() % (u - l + 1)) + l;
    }
}

int find_second_largest_smallest(int *a, int n)
{
    int i, sm= a[0], ssm= a[0], lar= a[0], slar= a[0], exists=0;
    for(i=1; i<n; i++)
    {
        if(a[i] < sm) //New smallest number found, so the current smallest number will now be the second smallest
        {
            ssm = sm;
            sm = a[i];
            exists=1;
        }
        else if((a[i] > sm) && (a[i] < ssm)) //Any number between the smallest and second smallest 
                                            // is the new second smallest element
        {
            ssm=a[i];
            exists=1;
        }

        //If the second smallest number exists, then we can be sure that the second largest number also exists
        //So we don't need to write exists=1 in the following blocks

        if(a[i] > lar) //New largest number found, so the current largest number will now be the second largest
        {
            slar = lar;
            lar = a[i];
        }

        else if((a[i] < lar) && (a[i] > slar)) //Any number between the largest and second largest 
                                            // is the new second largest element
        {
            slar=a[i];
        }
    }

    if(exists)
    {
        printf("Second smallest element = %d \nSecond largest element = %d\n", ssm, slar);
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    int i, n, l, u;
    printf("Enter no. of elements\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter range\nLower_limit\tUpper_limit\n");
    scanf("%d%d", &l, &u);
    insert_random_within_range(a, n, l, u);

    printf("Array is:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

    if(! find_second_largest_smallest(a, n)) //The function will return 0(false) if the required elements are not found
    {
        printf("Second largest and second smallest elements do not exist\n");
    }
    return 0;
}