#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[5];
    int i, index, input, output;

    printf("input 5 numbers... \n");
    for (i = 0; i < 5; i++) {
        printf("input a[%d]: ", i);
        scanf("%d", &input);
        a[i] = input;
    }
    
    for (i = 0; i < 5; i++) {
        index = 4 - i;
        output = a[index];
        printf("%d", output);
    }
    printf("\n");

    
    return 0;
}