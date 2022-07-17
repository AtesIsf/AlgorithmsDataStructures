#include <stdio.h>

int factorial(int n)
{
    if (n == 2)
        return 2;
    else
        return factorial(n-1) * n;
}

int main()
{
    printf("%d\n", factorial(5));
    return 0;
}