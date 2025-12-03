#include <stdio.h>
#include <stdlib.h>

void print_ascii(char *string) {
    for (;;) {
        printf("%d ", *string);
        if (*string == '\0') {
            break;
        }
        string++;
    }
    printf("\n");
}

int main() {
    char string[4];
    printf("input string: ");
    fgets(string, 4, stdin);
    print_ascii(string);

    return 0;
}