//Current time-complexity of REMOVE_BOTTOM_HALF = O(nlogn) (Strategy: Merge sort(nlogn), count(n), remove bottom(n))

#include<stdio.h>
#include<stdlib.h>

struct set
{
    int val;
    struct set *next;
};

void display(struct set *S)
{
    if(S == NULL)
    {
        return;
    }
    else if(S->next == NULL)
    {
        printf("%d\n", S->val);
        return;
    }
    else
    {
        printf("%d -> ",S->val);
        display(S->next);
    }
}

void INSERT(int x, struct set **S)
{
    struct set *New = (struct set*) malloc(sizeof( struct set ));
    New->val = x;
    New->next = *S; //To get O(1) complexity
    *S = New;
}

void FrontBackSplit(struct set* source, struct set** frontRef, struct set** backRef)
{
    struct set* fast;
    struct set* slow;
    slow = source;
    fast = source->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

struct set* SortedMerge(struct set* a, struct set* b)
{
    struct set* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->val >= b->val) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void MergeSort(struct set** S)
{
    struct set* head = *S;
    struct set* a;
    struct set* b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    FrontBackSplit(head, &a, &b);
 
    MergeSort(&a);
    MergeSort(&b);

    *S = SortedMerge(a, b);
}

int count_elements(struct set **S)
{
    struct set *temp = *S;
    int n = 0;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    return n;
}

void REMOVE_BOTTOM_HALF(struct set **S)
{
    int count, n = count_elements(S);
    struct set *temp;
    struct set *deleted, *del_next;
    MergeSort(S);
    temp = *S;

    count = 0;
    while(count < (n/2 - 1)) //As temp will go to its next node one extra time
    {
        count++;
        temp = temp->next;
    }
    
    //Unlinking next element and freeing allocated memory of the abandoned nodes
    deleted = temp->next;
    del_next = deleted;
    temp->next = NULL;
    while(del_next != NULL)
    {
        del_next = deleted->next;
        free(deleted);
        deleted = del_next;
    }
}

int main()
{
    int choice = 1, x;
    struct set *S = NULL;

    while(choice)
    {
        printf("Enter: \n\t0 to EXIT \n\t1 to use INSERT \n\t2 to use REMOVE_BOTTOM_HALF \n\t3 to display set\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
                printf("EXITING\n");
                break;
            case 1:
                printf("Enter value to be inserted\n");
                scanf("%d", &x);
                INSERT(x, &S);
                break;
            case 2:
                REMOVE_BOTTOM_HALF(&S);
                display(S);
                break;
            case 3:
                display(S);
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    }

    return 0;
}