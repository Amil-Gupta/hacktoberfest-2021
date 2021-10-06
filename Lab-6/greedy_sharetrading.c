#include<stdio.h>
#include<stdlib.h>

void greedy_sharetrading(float S[], float N[], float P[], float *X, float U, int n)
{
    int i, select, sold=0;
    float ratio[n];
    for(i=0; i<n; i++)
    {
        X[i] = 0;
        ratio[i] = P[i]/S[i];
    }

    while(U>0 && sold<n)
    {
        select = 0;
        for(i=1; i<n; i++)
        {
            if(ratio[i] > ratio[select])
            {
                select = i;
            }
        }

        if(S[select] * N[select] >= U)
        {
            X[select] = U / S[select];
        }

        else
        {
            X[select] = N[select];
        }

        U -= S[select] * X[select];
        ratio[select] = -1;
        sold++;
    }
}

int main()
{
    int i, n;
    float U, total_profit = 0;
    printf("Enter total number of commodities : ");
    scanf("%d", &n);
    printf("Enter amount of liquid cash to be generated : INR ");
    scanf("%f", &U);
    float S[n], N[n], P[n], X[n];

    printf("Enter Selling prices :\n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &S[i]);
    }

    printf("Enter available numbers :\n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &N[i]);
    }

    printf("Enter profits per share :\n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &P[i]);
    }

    greedy_sharetrading(S, N, P, &X[0], U, n);

    printf("Number of shares sold :\n");
    for(i=0; i<n; i++)
    {
        printf("%f\t", X[i]);
    }

    for(i=0; i<n; i++)
    {
        total_profit += X[i] * P[i];
    }
    printf("\nTotal profit: INR %f\n", total_profit);

    return 0;
}