/* explain why this code is incorrect.
print_pointでpのアドレスに割り当てられたストラクトを参照しようとしているが、
pはnullポインタであり、有効なアドレスを持っていない。
したがって、使用時に初期化されていないとしてエラーを吐いている。
*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void print_point(struct point *p)
{
    printf("(%d, %d)\n", p->x, p->y);
}

int main()
{
    struct point *p, *q = NULL;

    print_point(p);
    print_point(q);

    return 0;
}
