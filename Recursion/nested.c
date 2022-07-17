#include <stdio.h>

int foo(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        foo(foo(n-2));
    }
    return n;
}

int main()
{
    foo(5);
    return 0;
}