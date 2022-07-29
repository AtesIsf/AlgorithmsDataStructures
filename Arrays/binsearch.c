#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *arr, int target, int low, int high)
{
    if (! (low <= high)) return -1;

    int mid = (low+high)/2;
    
    if (target == arr[mid])
        return mid;

    else if (target > arr[mid])
        return binarysearch(arr, target, mid, high);

    else return binarysearch(arr, target, low, mid);
}

int main()
{
    int *arr = (int *) malloc(sizeof(int) * 100);
    for (int i = 1; i<=100; i++)
        arr[i] = i * 2;
    int index = binarysearch(arr, 80, 0, 99);
    printf("%d\n", index);
    return 0;
}