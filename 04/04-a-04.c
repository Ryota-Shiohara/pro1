/* explain here why this program is not correct
qはポインタとして初期化されていない。
結果として、存在しないアドレスに100を割り当てようとしている。
*/

#include <stdio.h>
#include <stdlib.h>

void pointer_assign(int *p, int x)
{
    *p = x;
}

int main()
{
    int *q;
    pointer_assign(q, 100);

    return 0;
}
