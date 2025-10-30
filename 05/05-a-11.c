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
    if (p != NULL)
        printf("(%d, %d)\n", p->x, p->y);
    else
        printf("no point\n");
}

int main()
{
    struct point *p;

    p = (struct point *)malloc(sizeof(struct point));
    p->x = 10;
    p->y = 5;

    free(p);
    print_point(p);

    return 0;
}
