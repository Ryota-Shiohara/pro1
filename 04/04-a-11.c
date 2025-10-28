#include <stdio.h>
#include <stdlib.h>


void print_char_array(char *array, int len) {
    int i;
    printf("regular order: ");
    for (i=0; i<len; i++) {
        printf("%c", *array++);
    }
    printf("\n");
}

void print_char_reverse(char *array, int len) {
    int i;
    printf("reverse order: ");
    array += len - 1;
    for (i=0; i<len; i++) {
        printf("%c", *array--);
    }
    printf("\n");
}


int main()
{
    char array[32];
    char c;
    int i;

    printf("input string (maxlen = 32): ");
    for (i=0;i<32;i++) {
        c = getchar();
        if (c == '\n') {
            break;
        } else {
            array[i] = c;
        }
    }
    print_char_array(array, i);
    print_char_reverse(array, i);



    return 0;
}