#include<stdio.h>

int main() {
    int a, b;
    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);
    
    if (a == b) {
        printf("%d equals %d.\n", a, a);
    } else if (a < b) {
        printf("%d is greater than %d.\n", b, a);
    } else if (a > b) {
        printf("%d is greater than %d.\n", a, b);
    }
    return 0;
}