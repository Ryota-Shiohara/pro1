/* 
after foo(a, 3): a[0] and a[2]? 2 4
O
after bar(a, 3): a[0] and a[2]? 3 5
O
*/
#include <stdio.h>
#include <stdlib.h>

void check_answer(int, int);

void foo(int x[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        x[i]++;
    }
}

void bar(int *x, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        x[i]++;
    }
} 

int main()
{
    int a[] = {1, 2, 3};
 
    foo(a, 3);
    printf("after foo(a, 3): a[0] and a[2]? ");
    check_answer(a[0], a[2]);

    bar(a, 3);
    printf("after bar(a, 3): a[0] and a[2]? ");
    check_answer(a[0], a[2]);

    return 0;
}

void check_answer(int x, int y)
{
    int xa, ya;

    if (scanf("%d %d", &xa, &ya) != 2) {
        printf("incorrect input\n");
        exit(1);
    }

    if (x == xa && y == ya) printf("O\n"); else printf("X\n");
}