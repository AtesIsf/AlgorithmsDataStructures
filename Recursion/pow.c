#include <stdio.h>

int power(int base, int exp)
{
    if (exp == 0)
        return 1;
    else
        return power(base, exp-1) * base;
}

int main()
{
    printf("%d\n", power(3, 4));
    return 0;
}