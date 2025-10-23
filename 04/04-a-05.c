#include <stdio.h>
#include <stdlib.h>

int scanf_int() {
    int x;
    if (scanf("%d", &x) != 1) {
        printf("incorrect input\n");
        exit(1);
    } else {
        return x;
    }
}

int scanf_float() {
    float x;
    if (scanf("%f", &x) != 1) {
        printf("incorrect input\n");
        exit(1);
    } else {
        return x;
    }
}

int main() {
    int x;
    float y;
    printf("input int: ");
    x = scanf_int();
    printf("    read: %d\n", x);
    printf("input float: ");
    y = scanf_float();
    printf("    read: %f\n", y);


    return 0;
}