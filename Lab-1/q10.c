#include<stdio.h>

int max(int a, int b)
{
    return div((a + b + abs(a - b)), 2); //Basically, we add the difference(absolute) to the smaller value,
                                        // thus making it equal to the bigger value. When we add them,
                                        // we get twice the bigger value, so dividing by 2 gives us the required
                                        // solution
}

int main()
{
    int a, b;
    printf("Enter 2 integers\n");
    scanf("%d%d", &a, &b);
    printf("Maximum of the two integers is %d\n", max(a, b));
    return 0;
}