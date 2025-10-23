/* copy & paste the execution result here

1: *p? 10
O
 2: *p? 15
O
 3: x? 15
O
 4: *q? 20
O
 5: *q? 27
O
 6: x? 15
O
 7: y? 27
O
 8: *q? 15
O
 9: *p? 18
O
10: *q? 18
O
11: x? 18
O
12: y? 27
O
*/

#include <stdio.h>
#include <stdlib.h>

void check_answer(int);

int main()
{
    int x = 10, y = 20;
    int *p, *q;

    p = &x;
    printf(" 1: *p? ");
    check_answer(*p);

    *p += 5;
    printf(" 2: *p? ");
    check_answer(*p);
    printf(" 3: x? ");
    check_answer(x);

    q = &y;
    printf(" 4: *q? ");
    check_answer(*q);

    *q += 7;
    printf(" 5: *q? ");
    check_answer(*q);
    printf(" 6: x? ");
    check_answer(x);
    printf(" 7: y? ");
    check_answer(y);

    q = p;
    printf(" 8: *q? ");
    check_answer(*q);
    
    *q += 3;
    printf(" 9: *p? ");
    check_answer(*p);
    printf("10: *q? ");
    check_answer(*q);
    printf("11: x? ");
    check_answer(x);
    printf("12: y? ");
    check_answer(y);

    return 0;
}

void check_answer(int a)
{
    int b;

    if (scanf("%d", &b) != 1) {
        printf("incorrect input\n");
        exit(1);
    }

    if (a == b)
        printf("O\n");
    else
        printf("X\n");
}
