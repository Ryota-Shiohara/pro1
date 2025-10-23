#include <stdio.h>
#include <stdlib.h>

int pre_inc(int *x)
{
    *x = *x + 1;
    return *x;
}

int post_inc(int *x)
{
    int y = *x;
    *x = *x + 1;
    return y;
}

int main()
{
    int x = 10, y;

    y = pre_inc(&x);
    if (x == 11 && y == 11)
        printf("O\n");
    else
        printf("X\n");

    y = post_inc(&x);
    if (x == 12 && y == 11)
        printf("O\n");
    else
        printf("X\n");

    return 0;
}
