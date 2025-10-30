/* explain why this code is incorrect.
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
