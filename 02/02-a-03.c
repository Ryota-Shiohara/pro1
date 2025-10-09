/* Here, copy and paste the execution results with all O's.
i = 2;
j = 5;
i = i + 3; i? 5
O
j = 7 * j; j? 35
O
i -= i + j; i? -35
O
i = j++; i? 35
O
j? 36
O
j = --i; j? 34
O
i? 34
O
 */
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, j, a;

    i = 2;
    j = 5;

    printf("i = %d;\n", i);
    printf("j = %d;\n", j);

    printf("i = i + 3; i? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
    i = i + 3;
    if (i == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    printf("j = 7 * j; j? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
    j = 7 * j;
    if (j == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    printf("i -= i + j; i? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
    i -= i + j;
    if (i == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    printf("i = j++; i? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
    i = j++;
    if (i == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    printf("j? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
    if (j == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    printf("j = --i; j? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
    j = --i;
    if (j == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    printf("i? ");
    if (scanf("%d", &a) != 1) {
        printf("incorrect input\n");
        exit(1);
    };
     if (i == a) {
        printf("O\n");
    } else {
        printf("X\n");
    }

    return 0;
}

