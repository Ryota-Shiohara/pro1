#include <stdio.h>
#include <stdlib.h>

int fib(int n) { 
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
       
}

int main() {
    int n;
    printf("input a non-negative number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("must be non-negative\n");
        exit(1);
    }
    printf("fib(%d) = %d\n", n, fib(n));

    return 0;
}