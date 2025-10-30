/* explain why this code is incorrect.
*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};


struct point *create_point_from_input()
{
    struct point *p;

    p = (struct point *)malloc(sizeof(struct point));
    if (p == NULL) {
        printf("out of memory");
        exit(1);
    }

    printf("input p.x p.y: ");
    if (scanf("%d %d", &p->x, &p->y) != 2) {
        printf("incorrect input");
        return NULL;
    }

    return p;
}

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

    p = create_point_from_input();
    print_point(p);
    free(p);

    return 0;
}
