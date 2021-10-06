#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int choose_random(int n)
{
    return (rand()%n);
}

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

int binary_search(int *a, int e, int l, int h)
{
    int m = (l+h)/2;
    if(a[m] == e)
    {
        return m;
    }
    else if(l == h) //exit condition
    {
        return -1;
    }
    else if(a[m] > e)
    {
        return binary_search(a, e, l, m-1);
    }
    else
    {
        return binary_search(a, e, m+1, h);
    }
}

int main()
{
    int n = 0, *a, i, choice = 1;
    clock_t start, end;
    double time;

    while(choice)
    {
        printf("Enter: \n\t0 to EXIT"
        "\n\t1 to change n"
        "\n\t2 to find best case time complexity"
        "\n\t3 to find worst case time complexity"
        "\n\t4 to find the average case time complexity\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
                printf("EXITING\n");
                break;
            case 1:
                if(n>0)
                {
                    destroy_prev_allocation(a, n);
                }
                printf("Enter new value of n\n");
                scanf("%d", &n);
                a = (int*) malloc(sizeof(int) * n);
                insert_rand_array(a, n);
                merge_sort_ascending(a, 0, n-1);
                // printf("Sorted array :\n");
                // for(i=0; i<n; i++)
                // {
                //     printf("%d\t", a[i]);
                // }
                printf("\n");
                break;
            case 2:
                start = clock();
                binary_search(a, a[(n-1)/2], 0, n-1);
                end=clock();
                time = (double) (end-start);
                printf("Best case time taken = %lf ticks\n", time);
                time = ((double) (end - start) )/CLOCKS_PER_SEC;
                printf("Best case time taken = %lf seconds\n", time);
                break;
            case 3:
                start = clock();
                binary_search(a, a[0], 0, n-1);
                end=clock();
                time = (double) (end-start);
                printf("Worst case time taken = %lf ticks\n", time);
                time = ((double) (end - start) )/CLOCKS_PER_SEC;
                printf("Worst case time taken = %lf seconds\n", time);
                break;
            case 4:
                start = clock();
                binary_search(a, a[choose_random(n)], 0, n-1);
                end = clock();
                time = (double) (end-start);
                printf("Average case time taken = %lf ticks\n", time);
                time = ((double) (end - start) )/CLOCKS_PER_SEC;
                printf("Average case time taken = %lf seconds\n", time);
                break;
            default:
                printf("INVALID CHOICE, try again\n");
        }
    }
    if(n>0)
    {
        destroy_prev_allocation(a, n);
    }
    return 0;
}