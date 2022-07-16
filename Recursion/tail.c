#include <stdio.h>

void foo(int n)
{
    if (n > 0)
    {
        foo(n-1); // The actions are performed in the return phase
        printf("%d\n", n);
    }
}

int main()
{
    foo(5);
    return 0;
}