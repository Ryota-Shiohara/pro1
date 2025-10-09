#include<stdio.h>

int main() {
    int n;
   
    printf("input n(60 <= n < 100): ");
    scanf("%d", &n);

    if (60 <= n && n < 80) {
        printf("60 + %d", n - 60);
    } else if (80 <= n && n < 100) {
        printf("4 * 20 + %d", n - 80);
    }

    return 0;

}