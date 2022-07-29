#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    
    for (int i = 1; i<5; i++)
    {
        if (i == 4)
        {
            arr[i-1] = arr[i];
            arr[i] = 0;
        }
        else arr[i-1] = arr[i];
    }
    for (int i = 0; i<5; i++)   
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}