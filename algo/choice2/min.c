#include <stdio.h>

#define BASE 1000000000
#define MAX_SIZE 100000

int main() {
    unsigned long long digits[MAX_SIZE] = {0};

    int m;
    printf("input m: ");
    scanf("%d", &m);

    digits[0] = 1;
    int size = 1;

    for (int k = 0; k < m; k++) {
        unsigned long long carry = 0;

        for (int i = 0; i < size; i++) {

            unsigned long long val = digits[i] * 2 + carry;

            digits[i] = val % BASE;
            carry = val / BASE;
        }

        if (carry > 0) {
            digits[size] = carry;
            size++;
        }
    }

    digits[0] -= 1;

    unsigned long long remainder = 0;

    for (int i = size - 1; i >= 0; i--) {
        unsigned long long val = digits[i] + remainder * BASE;

        digits[i] = val / 3;
        remainder = val % 3;
    }
    while (size > 1 && digits[size - 1] == 0) {
        size--;
    }

    printf("\nresult (m=%d): \n", m);
    printf("%llu", digits[size - 1]);
    for (int i = size - 2; i >= 0; i--) {
        printf("%09llu", digits[i]);
    }
    printf("\n");
    unsigned long long temp = digits[size - 1];
    int top_digits = 0;
    if (temp == 0)
        top_digits = 1;
    else {
        while (temp > 0) {
            temp /= 10;
            top_digits++;
        }
    }
    int total_digits = (size - 1) * 9 + top_digits;
    printf("total digits: %d\n", total_digits);

    return 0;
}