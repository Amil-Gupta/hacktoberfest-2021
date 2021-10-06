#include<stdio.h>

void SWAP(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main()
{
    int a, b, c;
    printf("Enter:\na  b  c\n");
    scanf("%d%d%d",&a,&b,&c);
    SWAP(&a, &b);
    SWAP(&a, &c);
    printf("Values after rotating are: \na\tb\tc \n%d\t%d\t%d\n", a, b, c);
    return 0;
}