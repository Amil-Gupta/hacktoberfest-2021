#include<stdio.h>

int isPrime1(int n, int *count)
{
    int i, c=0;
    (*count)++;
    
    for(i=1; i<=n; i++)
    {
        (*count)++;
        if(n % i == 0)
        {
            c++;
            (*count)++;
        }
    }
    (*count) += i;

    (*count)++;
    if(c == 2)
    {
        (*count)++;
        return 1;
    }

    (*count)++;
    return 0;
}

int isPrime2(int n, int *count)
{
    int i, c=0;
    (*count)++;

    for(i=2; i<n; i++)
    {
        (*count)++;
        if(n%i == 0)
        {
            c++;
            (*count)++;
            (*count)++;
            break;
        }
    }
    (*count) += i-1;

    (*count)++;
    if(c == 0 && n>1)
    {
        (*count)++;
        return 1;
    }

    (*count)++;
    return 0;
}

int isPrime3(int n, int *count)
{
    int i, c=0;
    (*count)++;

    
    for(i=2; i <= n/2; i++)
    {
        (*count)++;
        if(n%i == 0)
        {
            c++;
            (*count)++;
            (*count)++;
            break;
        }
    }
    (*count) += i-1;

    (*count)++;
    if(c == 0 && n>1)
    {
        (*count)++;
        return 1;
    }
    
    (*count)++;
    return 0;
}

int main()
{
    int n, i, check1, check2, check3, count1=0, count2=0, count3=0;

    for(i=0; i<10; i++)
    {
        count1 = count2 = count3 = 0;
        printf("Enter a number\n");
        scanf("%d", &n);
        check1 = isPrime1(n, &count1);
        check2 = isPrime2(n, &count2);
        check3 = isPrime3(n, &count3);

        printf("Checks\t: %d\t%d\t%d\n", check1, check2, check3);
        printf("Steps\t: %d\t%d\t%d\n", count1, count2, count3);
    }

    return 0;
}