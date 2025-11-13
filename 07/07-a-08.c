#include <stdio.h>
#include <stdlib.h>

float power(int a, int n) {
    float temp;
    if (n == 1) {
        return a;
    } else if (n == 2) {
        return a * a;
    } else if (n % 2 == 0) {
        temp = power(a, n/2);
        return temp * temp;
    } else {
        return power(a, n/2) * power(a, (n + 1)/2);
    }    
}

int main() {
    int a, n;
    printf("input two positive numbers: ");
    scanf("%d%d", &a, &n);
    if (a <= 0 || n <= 0) {
        printf("must be positive\n");
        exit(1);
    }
    printf("%d^%d = %f\n", a, n, power(a, n));

    return 0;
}