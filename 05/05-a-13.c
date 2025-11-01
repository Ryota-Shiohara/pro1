/* explain why this code is incorrect.
q＝pでqにpの示す構造体本体を渡しているように見えるが、
ここではポインタpの値を渡しているため、
qには構造体pの先頭アドレスが入っている。
ここで、pを解放してしまうと、そこには構造体が存在しなくなるため、
print_point(q)で変なデータが出力されてしまう。
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
    struct point *p, *q;

    p = (struct point *)malloc(sizeof(struct point));
    p->x = 10;
    p->y = 5;
    q = p;

    print_point(p);
    free(p);
    print_point(q);

    return 0;
}
