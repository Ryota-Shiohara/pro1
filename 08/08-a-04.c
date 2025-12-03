#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

size_t my_strlen(char *str) {
    str = chop(str);
    int i;
    for (i=0; *str != 0; i++) {
        str++;
    }
    return i;
}

int my_strcmp(char *str1, char *str2) {
    int i;
    if (my_strlen(str1) != my_strlen(str2)) {
        return 0;
    }
    for (i=0; i<my_strlen(str1); i++) {
        if (*str1 != *str2) {
            return 0;
        } else {
            str1++;
            str2++;
        }
    }
    return 1;
}

int main() {
    char string1[256];
    char string2[256];
    
    printf("input 1st string: ");
    fgets(string1, 256, stdin);
    printf("input 2nd string: ");
    fgets(string2, 256, stdin);
    printf("1st len: strlen == %lu, my_strlen == %lu\n", strlen(string1), my_strlen(string1));
    printf("2nd len: strlen == %lu, my_strlen == %lu\n", strlen(string2), my_strlen(string2));
    printf("%s", string1);
    if (my_strcmp(string1, string2)) {
        printf(" == ");
    } else {
        printf(" != ");
    }
    printf("%s\n", string2);
    return 0;
}