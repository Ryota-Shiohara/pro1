/* explain why this code is incorrect.
malloc でメモリを確保したのにも関わらず、使用後にメモリを開放していない。
動的にメモリを確保している意味がない。
*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void print_point(struct point *p)
{
    if (p != NULL)
        printf("(%d, %d)\n", p->x, p->y);
    else
        printf("no point\n");
}

int main()
{
    struct point *p, *q = NULL;

    p = (struct point *)malloc(sizeof(struct point));
    p->x = 10;
    p->y = 5;

    print_point(p);
    print_point(q);

    // do something that takes a long time...
    // the code is omitted
    // ...

    return 0;
}
