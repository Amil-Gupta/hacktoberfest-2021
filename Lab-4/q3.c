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

void find_max_min_dc(int *a, int l, int h, int *max, int *min) //Find maximum & minium elements by divide and conquer
{
    int lmax, hmax, lmin, hmin, m = (l+h)/2;

    if(h-l < 0) //If array is empty, we return maximum and minimum values as 0
    {
        *max = *min = 0;
    }

    else if(h-l <= 1) //0 means we have 1 element, 1 means we have 2 elements
    {
        if(a[l] >= a[h])
        {
            *max = a[l];
            *min = a[h];
        }
        else
        {
            *max = a[h];
            *min = a[l];
        }
    }

    else
    {
        find_max_min_dc(a, l, m, &lmax, &lmin);
        find_max_min_dc(a, m+1, h, &hmax, &hmin);

        if(lmax >= hmax)
        {
            *max = lmax;
        }
        else
        {
            *max = hmax;
        }

        if(lmin <= hmin)
        {
            *min = lmin;
        }
        else
        {
            *min = hmin;
        }
    }
}

void find_max_min_sf(int *a, int n, int *max, int *min) //Find maximum and minimum elements by straightforward method
{
    int i;
    if(n > 0)
    {
        *max = a[0];
        *min = a[0];
        for(i=1; i<n; i++)
        {
            if(a[i] > *max)
            {
                *max = a[i];
            }
            if(a[i] < *min)
            {
                *min = a[i];
            }
        }
    }

    else
    {
        *max = *min = 0; //If array has no elements, we take maximum and minimum values to be 0
    }
}

int main()
{
    int *a, n, i, choice, max, min;
    clock_t start, end;
    double time;

    printf("Enter 0 to EXIT, 1 for manual testing, or anything else for auto-testing\n");
    scanf("%d", &choice);
    
    //EXIT
    if(choice == 0)
    {
        printf("EXITING\n");
        return 0;
    }

    //Manual Testing
    else if(choice == 1)
    {
        printf("Enter size of array\n");
        scanf("%d", &n);
        a = (int*) malloc(sizeof(int) * n);
        insert_rand_array(a, n);


        printf("Display array?(1=YES, 0=NO)\n"); //So that we can avoid this when using larger values of n
        scanf("%d", &choice);
        if(choice)
        {
            printf("Array is:\n");
            for(i=0; i<n; i++)
            {
                printf("%d\t", a[i]);
            }
            printf("\n");
        }

        //Divide and Conquer
        start = clock();
        find_max_min_dc(a, 0, n-1, &max, &min);
        end = clock();
        time = ((double) (end - start) )/CLOCKS_PER_SEC;
        printf("Maximum element by divide and conquer method = %d\n", max);
        printf("Minimum element by divide and conquer method = %d\n", min);
        printf("Time taken by divide and conquer method = %lf seconds\n\n", time);

        //Straightforward
        start = clock();
        find_max_min_sf(a, n, &max, &min);
        end = clock();
        time = ((double) (end - start) )/CLOCKS_PER_SEC;
        printf("Maximum element by straightforward method = %d\n", max);
        printf("Minimum element by straightforward method = %d\n", min);
        printf("Time taken by straightforward method = %lf seconds\n\n", time);

        destroy_prev_allocation(a, n);

        return 0;
    }

    //Auto-testing
    printf("Array Size(n)\tTime taken in D&C\tTime taken in SF\n");
    for(n=5000; n<=50000; n+=5000)
    {
        a = (int*) malloc(sizeof(int) * n);
        insert_rand_array(a, n);

        //Divide and Conquer
        start = clock();
        find_max_min_dc(a, 0, n-1, &max, &min);
        end = clock();
        time = ((double) (end - start) )/CLOCKS_PER_SEC;
        printf("%d\t\t%lf\t\t", n, time);

        //Straightforward
        start = clock();
        find_max_min_sf(a, n, &max, &min);
        end = clock();
        time = ((double) (end - start) )/CLOCKS_PER_SEC;
        printf("%lf\n", time);

        destroy_prev_allocation(a, n);
    }

    return 0;
}