#include <stdio.h>
/*
Task: print all the fnumbers smaller than 10
in the Fibonacci Sequence
*/

void fibonacci(int a, int b, int n)
{
    int sum = a + b;
    printf("%d ", b);
    if (sum<=n)
    {
        fibonacci(b, sum, n);
    }
}

int main()
{
    fibonacci(0, 1, 10);
    printf("\n");
    return 0;
}