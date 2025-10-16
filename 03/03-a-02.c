/*　copy & paste the execution result here
in foo(y): x? 200
O
in foo(y): y? 101
O
in main after calling foo(y): y? 100
O
in bar(y): x? 200
O
in bar(y): y? 101
O
in main after calling bar(y): y? 100
O
in foo(y): x? 200
O
in foo(y): y? 101
O
in main after calling foo(y) again: y? 100
O
in bar(y): x? 300
O
in bar(y): y? 101
O
in main after calling bar(y) again: y? 100
O
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int);

int x = 100;

void foo(int y)
{
    int x = 100;

    x += y++;
    printf("in foo(y): x? ");
    check_answer(x);
    printf("in foo(y): y? ");
    check_answer(y);
}

void bar(int y)
{
    x += y++;
    printf("in bar(y): x? ");
    check_answer(x);
    printf("in bar(y): y? ");
    check_answer(y);
}

int main()
{
    int y = 100;

    foo(y);
    printf("in main after calling foo(y): y? ");
    check_answer(y);

    bar(y);
    printf("in main after calling bar(y): y? ");
    check_answer(y);

    foo(y);
    printf("in main after calling foo(y) again: y? ");
    check_answer(y);

    bar(y);
    printf("in main after calling bar(y) again: y? ");
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
