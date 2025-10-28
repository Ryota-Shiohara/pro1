#include <stdio.h>
#include <stdlib.h>


void read_array(int *array, int len) {
    int i;
    printf("input %d integers: ", len);
    for (i=0; i < len; i++) {
        scanf("%d", array++);
    }
}

void print_array(int *array, int len) {
    int i;
    
    for (i=0; i < len; i++) {
        printf("%d ", *array++);
    }
    printf("\n");
}

void dec_array(int *array, int len) {
    int i;
    
    for (i=0; i < len; i++) {
        (*array++)--;
    }
}

int main()
{
    int a[5], b[3];
    read_array(a, 5);
    read_array(b, 3);
    printf("array a: \n");
    print_array(a, 5);
    dec_array(a, 5);
    print_array(a, 5);
    printf("array b: \n");
    print_array(b, 3);
    dec_array(b, 3);
    print_array(b, 3);

    return 0;
}