#include <stdio.h>

void foo(int bar)
{
    /*
        Static variables are kept in the code section
        of the memory, so it's not reset on each call
        it acts the same way as a global variable would
    */
    static int n = 1;
    if(bar > 0)
    {
        printf("Param Value: %d Static value: %d\n", bar, n);
        n++;
        foo(bar-1);
    }
}

int main()
{
    foo(5);
    return 0;
}