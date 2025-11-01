/* copy & paste the execution result here.
in foo: p.x? 4
O
in foo: p.y? 6
O
in main, after foo(): p.x? 3
O
in main, after foo(): p.y? 5
O
in main, after foo(): q.x? 4
O
in main, after foo(): q.y? 6
O
in bar: p->x? 4
O
in bar: p->y? 6
O
in main, after bar(): p.x? 4
O
in main, after bar(): p.y? 6
O
in main, after r->x++; r->y++: r->x? 5
O
in main, after r->x++; r->y++: r->y? 7
O
in main, after r->x++; r->y++: p.x? 5
O
in main, after r->x++; r->y++: p.y? 7
O
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int);

struct point {
    int x;
    int y;
};

struct point foo(struct point p)
{
    p.x++;
    p.y++;
    printf("in foo: p.x? ");
    check_answer(p.x);
    printf("in foo: p.y? ");
    check_answer(p.y);

    return p;
}

struct point *bar(struct point *p)
{
    p->x++;
    p->y++;
    printf("in bar: p->x? ");
    check_answer(p->x);
    printf("in bar: p->y? ");
    check_answer(p->y);

    return p;
}

int main()
{
    struct point p = {3, 5}, q, *r;

    q = foo(p);
    printf("in main, after foo(): p.x? ");
    check_answer(p.x);
    printf("in main, after foo(): p.y? ");
    check_answer(p.y);

    printf("in main, after foo(): q.x? ");
    check_answer(q.x);
    printf("in main, after foo(): q.y? ");
    check_answer(q.y);


    r = bar(&p);
    printf("in main, after bar(): p.x? ");
    check_answer(p.x);
    printf("in main, after bar(): p.y? ");
    check_answer(p.y);

    r->x++;
    r->y++;

    printf("in main, after r->x++; r->y++: r->x? ");
    check_answer(r->x);
    printf("in main, after r->x++; r->y++: r->y? ");
    check_answer(r->y);

    printf("in main, after r->x++; r->y++: p.x? ");
    check_answer(p.x);
    printf("in main, after r->x++; r->y++: p.y? ");
    check_answer(p.y);


    return 0;
}

void check_answer(int a)
{
    int x;

    if (scanf("%d", &x) != 1) {
        printf("incorrect input\n");
        exit(1);
    }

    if (x == a)
        printf("O\n");
    else
        printf("X\n");
}
