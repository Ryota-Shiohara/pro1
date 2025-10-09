#include<stdio.h>

int main() {
    int a, b;
    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d / %d = %f\n", a, b, (float)a / b);
    printf("%d %% %d = %d\n", a, b, a % b);
    return 0;
}