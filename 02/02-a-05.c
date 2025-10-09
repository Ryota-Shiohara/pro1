#include<stdio.h>

int main() {
    int n, i, a, b;
    a = 0;
    b = 1;

    printf("input n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        b += a;
        a = b - a;
        //printf("%d\n", a); 
    }
    printf("fib(%d) = %d\n", n, a); 

    return 0;

}