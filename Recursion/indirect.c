#include <stdio.h>

void bar(int n);

void foo(int n)
{
    if (n>0)
    { 
        printf("Foo: %d\n", n);
        bar(n-3);
    }
}

void bar(int n)
{
    if (n>0)
    { 
        printf("Bar: %d\n", n);
        foo(n-1);
    }
}

int main()
{
    foo(10);
    return 0;
}