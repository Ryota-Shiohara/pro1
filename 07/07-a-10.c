#include <stdio.h>
#include <stdlib.h>

int isOdd(int);

int isEven(int n) {
    if (n == 0) {
        return 1;
    } else if (n > 0) {
        return isOdd(n - 1);
    } else {
        return isOdd(n + 1);
    }
}

int isOdd(int n) {
    if (n == 0) {
        return 0;
    } else if (n > 0) {
        return isEven(n - 1);
    } else {
        return isEven(n + 1);
    }
}


int main() {
    int n;
    printf("input an integer: ");
    scanf("%d", &n);
    
    printf("%d is ", n);
    if (isEven(n)) {
        printf("even\n");
    } else {
        printf("odd\n");
    }

    return 0;
}