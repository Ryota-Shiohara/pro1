#include <stdio.h>
#include <stdlib.h>

void print_ascii(char *string) {
    for (;;) {
        printf("%d ", *string);
        if (*string == 0) {
            break;
        }
        string++;
    }
    printf("\n");
}

char* chop(char *s) {
    char *r;
    r = s;
    for (;;) {
        if (*s == 0) {
            if (*--s == 10) {
                *s = 0;
            }
            break;
        }
        s++;
    }
    return r;
}

int main() {
    char string[4];
    printf("input string: ");
    fgets(string, 4, stdin);
    printf("before chop: ");
    print_ascii(string);
    printf("after chop: ");
    print_ascii(chop(string));

    return 0;
}