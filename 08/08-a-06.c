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

char *strrev(char *dst, char *src, size_t n)
{
    // fill in by yourself
    int i;
    char *result = dst;
    for (;*src != 0; src++) {
    }
    src--;
    
    for (i=0; i<n; i++) {
        *dst++ = *src--;
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

    printf("reversed: %s\n", strrev(dst, src, DST_LEN));

    return 0;
}
