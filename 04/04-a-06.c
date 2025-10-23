/* 
after r = foo(x) for the first time: x and r? 10 41
O
after r = foo(x) for the second time: x and r? 10 42
O
after r = bar(&x) for the first time: x and r? 12 51
O
after r = bar(&x) for the second time: x and r? 14 52
O
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int, int);

int g = 40;

int foo(int x)
{
    x += 2;
    return ++g;
}

int bar(int *x)
{
    static int g = 50;
    *x += 2;
    return ++g;
}

int main()
{
    int x = 10, r;

    r = foo(x);
    printf("after r = foo(x) for the first time: x and r? ");
    check_answer(x, r);

    r = foo(x);
    printf("after r = foo(x) for the second time: x and r? ");
    check_answer(x, r);

    r = bar(&x);
    printf("after r = bar(&x) for the first time: x and r? ");
    check_answer(x, r);

    r = bar(&x);
    printf("after r = bar(&x) for the second time: x and r? ");
    check_answer(x, r);

    return 0;
}

void check_answer(int x, int r)
{
    int xa, ra;

    if (scanf("%d %d", &xa, &ra) != 2) {
        printf("incorrect input\n");
        exit(1);
    }

    if (x == xa && r == ra) printf("O\n"); else printf("X\n");
}