/* explain why this code is incorrect.
set_pointで（1, 3）を設置しているものの、
そのアドレスがどこにあるか示すポインタはset_point内で定義されているため、
関数が終了するとポインタが消失し、main関数で用いることができなくなる
結果としてメモリの解放も行えなくなってしまう。
*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void set_point(int x, int y)
{
    struct point *p;

    if ((p = (struct point *)malloc(sizeof(struct point))) == NULL) {
        printf("out of memory\n");
        exit(1);
    }

    p->x = x;
    p->y = y;
}

int main()
{
    set_point(1, 3);
    return 0;
}
