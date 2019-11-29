#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *lhs, int *rhs)
{
    if (lhs == rhs)
        return;

    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

int partition(int ar[], int len)
{
    int i, pvt=0;

    // swap random slot selection to end.
    //  ar[len	-1] will hold the pivot value.
    swap(ar + (rand() % len), ar+(len-1));
    for (i=0; i<len; ++i)
    {
        if (ar[i] < ar[len-1])
            swap(ar + i, ar + pvt++);
    }

    // swap the pivot value into position
    swap(ar+pvt, ar+(len-1));
    return pvt;
}

void quicksort(int ar[], int len)
{
    if (len < 2)
        return;

    int pvt = partition(ar, len);
    quicksort(ar, pvt++); // note increment. skips pivot slot
    quicksort(ar+pvt, len-pvt);
}