#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC_LEN 256
#define DST_LEN 4

char *chop(char *s)
{
    // fill in by yourself
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

void print_ascii2(char *s, size_t n)
{
    int i = 0;

    while (i++ < n)
        printf("%3d ", *s++);
    printf("\n");
}

char *safe_strncpy(char *dst, char *src, size_t n)
{
    // fill in by yourself
    int i;
    char *result = dst;
    for (i=0; i<n; i++) {
        *dst++ = *src++;
    }
    dst--;
    *dst = 0;
    return result;
}

int main() 
{
    char src[SRC_LEN], dst[DST_LEN];

    printf("input a string: ");
    fgets(src, SRC_LEN, stdin);
    chop(src);

    printf("copied by strncpy(dst, src, %d): ", DST_LEN);
    print_ascii2(strncpy(dst, src, DST_LEN), DST_LEN);

    printf("copied by safe_strncpy(dst, src, %d): ", DST_LEN);
    print_ascii2(safe_strncpy(dst, src, DST_LEN), DST_LEN);

    return 0;
}
