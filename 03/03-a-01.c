/*　copy & paste the execution result here
in foo(x): x? 110
O
in main after calling foo(x): x? 100
O
in main after calling foo(x): y? 110
O
*/

#include <stdio.h>
#include <stdlib.h>

int foo(int);  // prototype declaration
void check_answer(int);

int main()
{
    int x = 100, y;

    y = foo(x);
    printf("in main after calling foo(x): x? ");
    check_answer(x);
    printf("in main after calling foo(x): y? ");
    check_answer(y);

    return 0;
}

int foo(int x)
{
    x += 10;
    printf("in foo(x): x? ");
    check_answer(x);

    return x;
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
