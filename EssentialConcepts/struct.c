#include <stdio.h>
#include <stdlib.h>

typedef struct complex
{
    int real;
    int imaginary;
}complex_t;

void printcompnum(complex_t comp)
{
    if (comp.imaginary > 0)
        printf("%d + %di\n", comp.real, comp.imaginary);
    else if (comp.imaginary < 0)
        printf("%d - %di\n", comp.real, abs(comp.imaginary));
    else
        printf("%d\n", comp.real);
}

int main()
{
    complex_t c;
    c.imaginary = 3;
    c.real = 2;
    printcompnum(c);

    c.imaginary = -2;
    c.real = 2;
    printcompnum(c);

    c.imaginary = 0;
    c.real = 2;
    printcompnum(c);
    return 0;
}
