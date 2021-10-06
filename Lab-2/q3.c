#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void destroy_prev_allocation(int *a, int n) // Destroys previously (dynamically allocated) memory from the array
{
    int i;
    for(i=0; i<n; i++)
    {
        free(a + i);
    }
}

void insert_rand_array(int *a, int n) // Inserts n random values into the array
{
    int i;
    for(i=0; i<n; i++)
    {
        a[i] = rand();
    }
}

void display(int *a, int n) // Displays array elements
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void insertion_sort_ascending(int *a, int n, long long int *count) // Sorts the array in ascending order using insertion sort
{
    int i, j, temp;
    (*count)++;
    for(i=1; i<n; i++)
    {
        j = i;
        (*count)++;
        temp = a[i];
        (*count)++;
        while( (temp < a[j-1]) && (j > 0) )
        {
            (*count)++; // for true checks of while loop
            a[j] = a[j-1];
            (*count)++;
            j--;
            (*count)++;
        }
        (*count)++; // for last check of while loop
        a[j] = temp;
        (*count)++;
    }
    (*count) += i;
}

void selection_sort_descending(int *a, int n) // Sorts the array in descending order using selection sort
{
    int i, j, max, temp;
    for(i=0; i<n; i++)
    {
        max = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] > a[max])
            {
                max = j;
            }
        }

        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }
}

void row_display(int *a, int n)
{
    long long int count1=0, count2=0, count3=0;
    insert_rand_array(a, n);

    // Random
    insertion_sort_ascending(a, n, &count1);

    // Ascending
    insertion_sort_ascending(a, n, &count2); //Array is already sorted in ascending order

    // Descending
    selection_sort_descending(a, n);
    insertion_sort_ascending(a, n, &count3);

    printf("%d\t\t%lld\t\t\t%lld\t\t\t\t\t%lld\n", n, count1, count2, count3);
}

int main()
{
    int choice=1, *a, n=0;
    long long int count=0;

    while(choice)
    {
        printf("\n0. Quit"
        "\n1. n Random numbers=>Array"
        "\n2. Display the Array"
        "\n3. Sort the Array in Ascending Order by using Insertion Sort Algorithm"
        "\n4. Sort the Array in Descending Order by using any sorting algorithm"
        "\n5. Time Complexity to sort ascending of random data"
        "\n6. Time Complexity to sort ascending of data already sorted in ascending order"
        "\n7. Time Complexity to sort ascending of data already sorted in descending order"
        "\n8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n"
        );

        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
            printf("Exiting\n");
            break;

            case 1:
            destroy_prev_allocation(a, n);
            printf("Enter n\n");
            scanf("%d", &n);
            a = (int*) malloc( sizeof(int) * n );
            insert_rand_array(a, n);
            break;

            case 2:
            display(a, n);
            break;

            case 3:
            insertion_sort_ascending(a, n, &count);
            break;

            case 4:
            selection_sort_descending(a, n);
            break;

            case 5:
            count = 0;
            insertion_sort_ascending(a, n, &count);
            printf("Step-count : %lld\n", count);
            break;

            case 6:
            insertion_sort_ascending(a, n, &count);
            count = 0;
            insertion_sort_ascending(a, n, &count); // The array is already sorted in ascending order
            printf("Step-count : %lld\n", count);
            break;

            case 7:
            selection_sort_descending(a, n);
            count = 0;
            insertion_sort_ascending(a, n, &count); // The array is already sorted in descending order
            printf("Step-count : %lld\n", count);
            break;

            case 8:
            printf("SI No."
            "\tValue of n"
            "\tTime complexity(Random Data)"
            "\tTime complexity(Data in Ascending)"
            "\tTime complexity(Data in Descending)\n"
            );
            for(n=5000; n<=50000; n += 5000)
            {
                a = (int*) malloc( sizeof(int) * n );
                printf("%d\t", (n/5000));
                row_display(a, n);
                destroy_prev_allocation(a, n);
            }
            break;

            default:
            printf("\t\tINVALID CHOICE\n");
        }
    }

    return 0;
}