#include <stdio.h>

int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return fact(n-1) * n;
}

int c(int n, int r)
{
    if (r > n)
        return -1;

    int f1, f2, f3;
    f1 = fact(n);
    f2 = fact(r);
    f3 = fact(n-r);
    return f1/(f2 * f3);
}

// Using Pascal's triangle
int pasc(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return pasc(n-1, r-1) + pasc(n-1, r);
}

int main()
{
    printf("%d\n", c(5, 3));
    printf("%d\n", pasc(5, 3));
    return 0;
}