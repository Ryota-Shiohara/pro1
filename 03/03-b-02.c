#include<stdio.h>
#include<stdlib.h>

int prime_num[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 39, 97};
int prime_len = 25;
int max_index = 15;

void print_eq(int);

int main() {
    int i;
    for (i=4; i<=100; i += 2) {
        print_eq(i);
    }

    return 0;
}

int check_prime(int number) {
    int r = 0, i;
    for (i=0; i < prime_len; i++) {
        if (number == prime_num[i]) {
            r = 1;
        } else {
            continue;
        }
    }

    return r;
}

void print_eq(int number) {
    int i;
    printf("%d", number);
    for (i=0; i<max_index; i++) {
        if (check_prime(number-prime_num[i])) {
            if (prime_num[i] > number-prime_num[i]) {
                break;
            }
            printf(" = %d + %d", prime_num[i], number-prime_num[i]);
        } else {
            continue;
        }
    } 
    printf("\n");
}