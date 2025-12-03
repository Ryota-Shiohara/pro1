#include <stdio.h>
#include <stdlib.h>

void print_changed(char *string) {
    for (;;) {
        char c = *string;
        if ('a'<= c && c<='z') {
            c -= 32;
        } else if ('A' <= c && c <= 'Z'){
            c += 32;
        }
        printf("%c", c);
        if (c == '\0') {
            break;
        }
        string++;
    }
    printf("\n");
}

int main() {
    char string[256];
    printf("input string: ");
    fgets(string, 256, stdin);
    print_changed(string);

    return 0;
}