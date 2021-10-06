// Approaches and strategies I could think of:

//1. Keep searching for even numbers and inserting them at the start of the array
//OR keep searching for odd numbers and inserting them at the end of the array

//2. Make a new array. Traverse the original array looking for even numbers and put them in the new array.
//Then traverse the original array looking for odd numbers and put them in the new array.

//3. Make a new array. Traverse the original array once. Whenever an even number is encountered, insert it at the
//start of the new array. Whenever an odd number is encountered, insert it at the end of the new array.

//4. THE ONE THAT I AM USING IN THIS PROGRAM. Take two variables, one will traverse the array forward from the
//beginning. The other will go backwards from the end. In each iteration, we use the forward-moving variable to find
//the first odd element. If it is found, the backwards-moving variable is used to find the last even element.
//The two elements are swapped. We repeat this while the forward-moving variable is at an index less than the
//backwards-moving variable. 
//(In other words, while the first odd number exists before the last even number.)
//This is the method of least complexity that I could think of.

#include<stdio.h>

void insert_random_positive(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i] = abs(rand());
        printf("%d\t",a[i]);
    }
    printf("\n");
}

sort_even_odd(int *a, int n) //Basically, we need to swap the first odd element with the last odd element
                            //as long as the former appears before the latter
{
    int forward_move=-1, backward_move=n-1, temp;
    while( forward_move < backward_move )
    {
        forward_move++;
        if(a[forward_move] % 2 == 1)
        {
            while( (a[backward_move] % 2 != 0) && ( forward_move < backward_move ) )
            {
                backward_move--;
            }
            temp = a[forward_move];
            a[forward_move] = a[backward_move];
            a[backward_move] = temp;
        }
    }
}

display_array(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    int a[n];
    insert_random_positive(a, n);
    sort_even_odd(a,n);
    display_array(a,n);
    return 0;
}