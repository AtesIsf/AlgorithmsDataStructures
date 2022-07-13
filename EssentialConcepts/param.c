#include <stdio.h>
#include <stdlib.h>

void foo(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    foo(arr, n);
    return 0;
}
