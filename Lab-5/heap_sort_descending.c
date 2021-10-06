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

int left(int i)
{
    return (2*i + 1);
}

int right(int i)
{
    return (2*i + 2);
}

int parent(int i)
{
    return ((i - 1)/2);
}

void min_heapify(int a[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    int temp;

    if(l<n && a[l]<a[smallest])
    {
        smallest = l;
    }

    if(r<n && a[r]<a[smallest])
    {
        smallest = r;
    }

    if(smallest != i)
    {
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;

        min_heapify(a, n, smallest);
    }
}

void build_min_heap(int a[], int n)
{
    int i;
    for(i=n/2 - 1; i>=0; i--)
    {
        min_heapify(a, n, i);
    }
}

void heap_sort_descending(int a[], int n)
{
    int i, temp;

    build_min_heap(a, n);

    for(i = n-1; i>0; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;

        min_heapify(a, i, 0);
    }
}

void selection_sort_ascending(int *a, int n) // Sorts the array in ascending order using selection sort
{
    int i, j, min, temp;
    for(i=0; i<n; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void row_display(int *a, int n)
{
    clock_t start, end;
    double time1, time2, time3;
    insert_rand_array(a, n);

    // Random
    start = clock();
    heap_sort_descending(a, n);
    end = clock();
    time1 = ((double) (end - start) )/CLOCKS_PER_SEC;

    // Ascending
    start = clock();
    heap_sort_descending(a, n); //Array is already sorted in ascending order
    end = clock();
    time2 = ((double) (end - start) )/CLOCKS_PER_SEC;

    // Descending
    selection_sort_ascending(a, n);
    start = clock();
    heap_sort_descending(a, n);
    end = clock();
    time3 = ((double) (end - start) )/CLOCKS_PER_SEC;

    printf("%d\t\t%lf\t\t\t%lf\t\t\t\t%lf\n", n, time1, time2, time3);
}

int extract_smallest(int a[], int n)
{
    build_min_heap(a, n);

    return a[0];
}

void min_heap_change(int a[], int n, int i, int key)
{
    int temp, p, prev = a[i];
    a[i] = key;
    if(i >= n)
    {
        printf("Invalid index\n");
    }
    else
    {
        if(key > prev)
        {
            min_heapify(a, n, i);
        }
        else if(key > prev)
        {
            p = parent(i);
            while(i>0 && a[p]>a[i])
            {
                temp = a[i];
                a[i] = a[p];
                a[p] = temp;

                i = p;
                p = parent(i);
            }
        }
    }
}

void insert_at_array_end(int **a, int *n, int key)
{
    int i, temp[*n];

    for(i=0; i<(*n); i++)
    {
        temp[i] = (*a)[i];
    }

    destroy_prev_allocation(*a, *n);

    (*n)++;
    *a = (int*) malloc(sizeof(int) * (*n));

    for(i=0; i<((*n)-1); i++)
    {
        (*a)[i] = temp[i];
    }

    (*a)[i] = key;
}

void min_heap_insert(int **a, int *n, int key)
{
    int i, p, temp;
    insert_at_array_end(a, n, key);

    i = (*n)-1;
    p = parent(i);

    while(i>0 && (*a)[p]>(*a)[i])
    {
        temp = (*a)[i];
        (*a)[i] = (*a)[p];
        (*a)[p] = temp;

        i = p;
        p = parent(i);
    }
}

void min_heap_delete(int **a, int *n, int i)
{
    int temp = (*a)[i];
    (*a)[i] = (*a)[*n-1];
    (*a)[*n-1] = temp;
    (*n)--;
    free((*a)+(*n));
    build_min_heap(*a, *n);
}

int main()
{
    int choice=1, n=0, *a, i, key, s;
    clock_t start, end;
    double time;

    while(choice)
    {
        printf("0. Quit"
        "\n1.  n Random numbers=>Array"
        "\n2.  Display the Array"
        "\n3.  Sort the Array in Descending Order by using Max-Heap Sort technique"
        "\n4.  Sort the Array in Ascending Order by using any algorithm"
        "\n5.  Time Complexity to sort descending of random data"
        "\n6.  Time Complexity to sort descending of data already sorted in ascending order"
        "\n7.  Time Complexity to sort descending of data already sorted in descending order"
        "\n8.  Time Complexity to sort descending all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000"
        "\n9.  Extract smallest element"
        "\n10. Replace value at a node with new value"
        "\n11. Insert a new element"
        "\n12. Delete an element\n");

        scanf("%d", &choice);

        if(choice == 0)
        {
            printf("EXITING\n");
            break;
        }
        switch(choice)
        {
            case 1:
                if(n > 0)
                {
                    destroy_prev_allocation(a, n);
                }
                printf("Enter n : ");
                scanf("%d", &n);
                if(n > 0)
                {
                    a = (int*) malloc(sizeof(int) * n);
                    insert_rand_array(a, n);
                }
                break;
            
            case 2:
                display(a, n);
                break;

            case 3:
                heap_sort_descending(a, n);
                display(a, n);
                break;

            case 4:
                selection_sort_ascending(a, n);
                display(a,n);
                break;
            
            case 5:
                if(n > 0)
                {
                    destroy_prev_allocation(a,n);
                    a = (int*) malloc(sizeof(int) * n);
                    insert_rand_array(a, n);
                }
                start = clock();
                heap_sort_descending(a, n);
                end = clock();
                time = ((double) (end - start) )/CLOCKS_PER_SEC;
                printf("Time taken : %lf seconds\n", time);
            break;

            case 6:
                if(n > 0)
                {
                    destroy_prev_allocation(a,n);
                    a = (int*) malloc(sizeof(int) * n);
                    insert_rand_array(a, n);
                }
                heap_sort_descending(a, n);
                start = clock();
                heap_sort_descending(a, n);
                end = clock();
                time = ((double) (end - start) )/CLOCKS_PER_SEC;
                printf("Time taken : %lf seconds\n", time);
                break;
            
            case 7:
                if(n > 0)
                {
                    destroy_prev_allocation(a,n);
                    a = (int*) malloc(sizeof(int) * n);
                    insert_rand_array(a, n);
                }
                selection_sort_ascending(a, n);
                start = clock();
                heap_sort_descending(a, n);
                end = clock();
                time = ((double) (end - start) )/CLOCKS_PER_SEC;
                printf("Time taken : %lf seconds\n", time);
                break;
            
            case 8:
                if(n > 0)
                {
                    destroy_prev_allocation(a,n);
                    a = (int*) malloc(sizeof(int) * n);
                    insert_rand_array(a, n);
                }
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
            
            case 9:
                s = extract_smallest(a, n);
                printf("Largest element = %d\n", s);
                break;

            case 10:
                build_min_heap(a, n);
                printf("Heap is :\n");
                display(a, n);
                printf("Enter index to replace : ");
                scanf("%d", &i);
                printf("Enter value to replace current value : ");
                scanf("%d",&key);
                min_heap_change(a, n, i, key);
                display(a, n);
                break;
            
            case 11:
                build_min_heap(a, n);
                printf("Heap is :\n");
                display(a, n);
                printf("Enter value to insert : ");
                scanf("%d", &key);
                min_heap_insert(&a, &n, key);
                display(a, n);
                break;
            
            case 12:
                build_min_heap(a, n);
                printf("Heap is :\n");
                display(a, n);
                printf("Enter index to delete : ");
                scanf("%d", &i);
                min_heap_delete(&a, &n, i);
                display(a, n);
                break;
            
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}