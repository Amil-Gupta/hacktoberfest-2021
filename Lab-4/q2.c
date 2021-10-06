#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

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

void merge(int *a, int p, int q, int r)
{
    int i = p, j = q+1, next = 0;
    int sorted[r-p+1];
    while( (i<=q) && (j<=r) )
    {
        if(a[i] <= a[j])
        {
            sorted[next++] = a[i++];
        }

        else
        {
            sorted[next++] = a[j++];
        }
    }
    while(i<=q)
    {
        sorted[next++] = a[i++];
    }
    while(j<=r)
    {
        sorted[next++] = a[j++];
    }
    for(i=p; i<=r; i++) //time complexity of the step remains O(n)
    {
        a[i] = sorted[i-p];
    }
}

void merge_sort_ascending(int *a, int p, int r) // Sorts the array in ascending order using merge sort
{
    int q;
    if(p<r)
    {
        q = (p+r-1)/2;
        merge_sort_ascending(a, p, q);
        merge_sort_ascending(a, q+1, r);
        merge(a, p, q, r);
    }
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
    clock_t start, end;
    double time1, time2, time3;
    insert_rand_array(a, n);

    // Random
    start = clock();
    merge_sort_ascending(a, 0, n-1);
    end = clock();
    time1 = ((double) (end - start) )/CLOCKS_PER_SEC;

    // Ascending
    start = clock();
    merge_sort_ascending(a, 0, n-1); //Array is already sorted in ascending order
    end = clock();
    time2 = ((double) (end - start) )/CLOCKS_PER_SEC;

    // Descending
    selection_sort_descending(a, n);
    start = clock();
    merge_sort_ascending(a, 0, n-1);
    end = clock();
    time3 = ((double) (end - start) )/CLOCKS_PER_SEC;

    printf("%d\t\t%lf\t\t\t%lf\t\t\t\t%lf\n", n, time1, time2, time3);
}

int main()
{
    int choice=1, *a, n=0;
    clock_t start, end;
    double time;

    while(choice)
    {
        printf("\n0. Quit"
        "\n1. n Random numbers=>Array"
        "\n2. Display the Array"
        "\n3. Sort the Array in Ascending Order by using merge sort Algorithm"
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
            merge_sort_ascending(a, 0, n-1);
            break;

            case 4:
            selection_sort_descending(a, n);
            break;

            case 5:
            start = clock();
            merge_sort_ascending(a, 0, n-1);
            end = clock();
            time = ((double) (end - start) )/CLOCKS_PER_SEC;
            printf("Time taken : %lf seconds\n", time);
            break;

            case 6:
            merge_sort_ascending(a, 0, n-1);
            start = clock();
            merge_sort_ascending(a, 0, n-1); // The array is already sorted in ascending order
            end = clock();
            time = ((double) (end - start) )/CLOCKS_PER_SEC;
            printf("Time taken : %lf seconds\n", time);
            break;

            case 7:
            selection_sort_descending(a, n);
            start = clock();
            merge_sort_ascending(a, 0, n-1); // The array is already sorted in descending order
            end = clock();
            time = ((double) (end - start) )/CLOCKS_PER_SEC;
            printf("Time taken : %lf seconds\n", time);
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
    if(n>0)
    {
        destroy_prev_allocation(a, n);
    }
    return 0;
}