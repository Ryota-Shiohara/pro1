#include <stdio.h>
#include <stdlib.h>

void print_seq(int number) {
    
    if (number > 1) {
        print_seq(number - 1);
    }
    printf("%d ", number);
    
}

int main() {
    int max;
    printf("input a positive number: ");
    scanf("%d", &max);
    print_seq(max);
    printf("\n");

    return 0;
}