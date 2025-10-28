/* 
after p = a, *p and *(p + 1)? 5 4
O
after q = *p++, *p and q? 4 5
O
after p = &a[2]; q = ++*p, *p and q? 4 4
O
after q = *++p, *p and q? 2 2
O

B)が正しい
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int, int);

int main()
{
    int *p, q, a[] = {5, 4, 3, 2, 1};

    p = a;
    printf("after p = a, *p and *(p + 1)? ");
    check_answer(*p, *(p + 1));

    q = *p++;
    printf("after q = *p++, *p and q? ");
    check_answer(*p, q);

    p = &a[2]; q = ++*p;
    printf("after p = &a[2]; q = ++*p, *p and q? ");
    check_answer(*p, q);

    q = *++p;
    printf("after q = *++p, *p and q? ");
    check_answer(*p, q);

    return 0;
}

void check_answer(int x, int y)
{
    int a, b;
 
    if (scanf("%d %d", &a, &b) != 2) {
        printf("incorrect input\n");
        exit(1);
    }

    if (x == a && y == b) printf("O\n"); else printf("X\n");
}