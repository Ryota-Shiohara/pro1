#include <stdio.h>
#include <stdlib.h>


void print_char_array(char *array, int len) {
    int i;
    printf("   input string: ");
    for (i=0; i<len; i++) {
        printf("%c", *array++);
    }
    printf("\n");
}

void print_char_reverse(char *array, int len) {
    int i;
    printf("reversed string: ");
    array += len - 1;
    for (i=0; i<len; i++) {
        printf("%c", *array--);
    }
    printf("\n");
}

void print_result(char *array, int len) {
    int i, isP = 1;
    char *small, *large;
    small = array;
    large = array + len - 1;
    for (i=0; i<len; i++) {
        if (*small++ == *large--) {
            continue;
        } else {
            isP = 0;
            break;
        }
    }

    if (isP) {
        printf("Yes! Palindrome!\n");
    } else {
        printf("No...\n");
    }
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
    print_result(array, i);

    return 0;
}