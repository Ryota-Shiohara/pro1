/* copy & paste the execution result here
foo: x? 110
O
foo: *p? 210
O
main: x? 100
O
main: y? 210
O
bar: y? 120
O
bar: *q? 120
O
main: x? 120
O
main: y? 210
O
bar: y? 140
O
bar: *q? 230
O
main: x? 120
O
main: y? 230
O
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int);

void foo(int x, int *p)
{
    x += 10;
    *p += 10;

    printf("foo: x? ");
    check_answer(x);
    printf("foo: *p? ");
    check_answer(*p);
}

void bar(int y, int *q)
{
    y += 20;
    *q += 20;

    printf("bar: y? ");
    check_answer(y);
    printf("bar: *q? ");
    check_answer(*q);
}

int main()
{
    int x = 100, y = 200, *p;

    foo(x, &y);
    printf("main: x? ");
    check_answer(x);
    printf("main: y? ");
    check_answer(y);

    bar(x, &x);
    printf("main: x? ");
    check_answer(x);
    printf("main: y? ");
    check_answer(y);

    p = &y;
    bar(x, p);
    printf("main: x? ");
    check_answer(x);
    printf("main: y? ");
    check_answer(y);

    return 0;
}

void check_answer(int a)
{
    int b;

    if (scanf("%d", &b) != 1) {
        printf("incorrect input\n");
        exit(1);
    }

    if (a == b)
        printf("O\n");
    else
        printf("X\n");
}
