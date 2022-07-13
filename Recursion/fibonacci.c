#include <stdio.h>
/*
Task: print all the fnumbers smaller than 10
in the Fibonacci Sequence
*/

void fibonacci(int a, int b, int n)
{
    int sum = a + b;
    printf("%d ", b);
    if (sum<=10)
    {
        fibonacci(b, sum, n+1);
    }
}

int main()
{
    fibonacci(0, 1, 1);
    printf("\n");
    return 0;
}