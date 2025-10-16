#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[100];
    int n, i, input, min, max, sum = 0;

    printf("input #(1-100) of numbers: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("n (%d) should be 1..100\n", n);
        exit(1);
    }
    for (i = 0; i < n; i++) {
        printf("input a[%d]: ", i);
        scanf("%d", &a[i]);
        input = a[i];
        if (i == 0) {
            min = input;
            max = input;
        } else if (input < min) {
            min = input;
        } else if (input > max) {
            max = input;
        }
        sum += input;
    }

    printf("min = %d, max = %d, ave = %f\n", min, max, (float)sum/n);
    
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");

    
    return 0;
}