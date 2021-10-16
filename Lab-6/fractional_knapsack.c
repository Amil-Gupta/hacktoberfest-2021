/*Write a program to implementation of Fractional Knapsack algorithm*/
#include<stdio.h>
#include<stdlib.h>

void fractional_knapsack(int value[], int weight[], int n, int limit, int *knapsack)
{
    int ratio[n], i, j, select, selected = 0;
    for(i=0; i<n; i++)
    {
        ratio[i] = value[i]/weight[i];
    }

    while(limit > 0 && selected < n)
    {
        select = 0;
        for(i=1; i<n; i++)
        {
            if(ratio[i] > ratio[select])
            {
                select = i;
            }
        }
        if(weight[select] >= limit)
        {
            knapsack[select] = limit;
        }
        else
        {
            knapsack[select] = weight[select];
        }
        limit -= weight[select];
        ratio[select] = -1;

        selected++;
    }
}

int main()
{
    int i, n, limit;
    printf("Enter number of items : ");
    scanf("%d", &n);
    printf("Enter size of knapsack : ");
    scanf("%d", &limit);
    int value[n], weight[n], knapsack[n];

    printf("Enter values :\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &value[i]);

        knapsack[i] = 0;
    }

    printf("Enter weights :\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &weight[i]);
    }

    fractional_knapsack(value, weight, n, limit, &knapsack[0]);

    printf("Knapsack : \n");

    for(i=0; i<n; i++)
    {
        printf("%d\t",knapsack[i]);
    }

    return 0;
}
