/* explain here why this program is not correct
*/

#include <stdio.h>
#include <stdlib.h>

int *foo(int x)
{
    int y = x * 10;
    return &y;
}

int main()
{
    int *p;

    p = foo(100);
    printf("*p = %d\n", *p);

    return 0;
}
