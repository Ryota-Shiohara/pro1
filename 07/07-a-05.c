#include <stdio.h>
#include <stdlib.h>


int fib(int n) { 
    static int memo[50] = {1,1};
    if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
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