/* 
yがx以上のときはyの値を返す。
それ以外のときはzの値を返す。
*/
#include <stdio.h>
#include <stdlib.h>

int t(int x, int y, int z) {
    if (x <= y) {
        return y;
    } else {
        return t(t(x-1, y, z), t(y-1, z, x), t(z-1, x, y));
    }
}

int main() {
    int x, y, z;
    printf("input three integers: ");
    scanf("%d%d%d", &x, &y, &z);
    printf("T(%d, %d, %d) = %d\n", x, y, z, t(x, y, z));

    return 0;
}