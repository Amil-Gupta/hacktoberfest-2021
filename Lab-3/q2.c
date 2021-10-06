//For the first UDF, space complexity is O(1) as a method without counting could not be found

#include<stdio.h>
#include<math.h>

void udf_a(int *a, int n) //Time complexity: O(n^2)
{
    int i, j, count;
    for(i=0; i<n; i++)
    {
        count = 0;
        for(j=0; j<n; j++)
        {
            if(a[j] == a[i])
            {
                count++;
            }

            if(count > (n/2) )
            {
                printf("%d occurs more than (n/2) times in the array\n", a[i]);
                return;
            }
        }
    }

    printf("No element occurs more than (n/2) times in the array\n");
}

void udf_b(int *a, int n) //Time complexity: O(n), Moore's Voting Algorithm
{
    int maj_index = 0, count = 1, i;

    //Find candidate
    for(i=1; i<n; i++)
    {
        if(a[i] == a[maj_index])
        {
            count++;
        }
        else
        {
            count--;
        }

        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }

    //Check for majority
    count = 0;
    for(i=0; i<n; i++)
    {
        if(a[i] == a[maj_index])
        {
            count++;
        }

        if( count > (n/2) ) //modified as per the question
        {
            printf("%d occurs more than (n/2) times in the array\n", a[i]);
            return;
        }
    }

    printf("No element occurs more than (n/2) times in the array\n");
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

    udf_a(a, n);

    udf_b(a, n);

    return 0;
}