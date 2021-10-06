#include<stdio.h>

void insert_random_duplicates(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i] = abs(rand()%(n-1));
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int count_and_replace(int *a, int n, int e)
{
    int i, count=0;
    for(i=0; i<n; i++)
    {
        if(a[i] == e)
        {
            count++;
            a[i] = -1;
        }
    }
    return count;
}

void count_duplicates(int *a, int n)
{
    int i, j, max_dup=0, max_dup_element=a[0], count, count_dup=0, e;
    for(i=0;i<n;i++)
    {
        if(a[i] >= 0)
        {
            e=a[i]; //Doing this because a[i] will become -1 after count_and_replace()
            count = count_and_replace(a, n, e);
            if(count>1)
            {
                count_dup++;
                if(count >  max_dup)
                {
                    max_dup_element = e;
                }
            }
        }
    }
    printf("Number of duplicate elements = %d \nElement with maximum duplicates = %d\n", count_dup, max_dup_element);
}

int main()
{
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    insert_random_duplicates(a, n);
    count_duplicates(a,n);
    return 0;
}