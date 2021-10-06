#include<stdio.h>
#include<time.h>

int main()
{
    while(1)
    {
        printf("%lf\n", (double) clock()/CLOCKS_PER_SEC);
    }
}