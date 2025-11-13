#include <stdio.h>
#include <stdlib.h>

int ackerman(int m, int n) {
    
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackerman(m - 1, 1);
    } else {
        return ackerman(m - 1, ackerman(m, n - 1));
    }
}

int main() {
    int m, n;
    printf("input two non-negative numbers: ");
    scanf("%d%d", &m, &n);
    if (m < 0 || n < 0) {
        printf("must be non-negative\n");
        exit(1);
    }
    printf("ackerman(%d, %d) = %d\n", m, n, ackerman(m, n));

    return 0;
}