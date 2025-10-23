/* 
after p = a, *p? 1
O
after p++, *p? 2
O
after p--, *p? 1
O
after p += 2, *p? 3
O
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int);

int main()
{
    int *p, a[] = {1, 2, 3};

    p = a;
    printf("after p = a, *p? ");
    check_answer(*p);

    ++p;
    printf("after p++, *p? ");
    check_answer(*p);

    p--;
    printf("after p--, *p? ");
    check_answer(*p);

    p += 2;
    printf("after p += 2, *p? ");
    check_answer(*p);

    return 0;
}

void check_answer(int x)
{
    int a;

    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    }

    if (x == a) printf("O\n"); else printf("X\n");
}