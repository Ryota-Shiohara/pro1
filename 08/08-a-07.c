#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define DEFAULT_FNAME   "sample-text-1.txt"
#define MAX_TARGET     256

char *read_document(const char *, size_t*);
void free_document(char *);
void highlight_word(const char *, const char *, const char *);

// you can add your code definitions here
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

char *search_string(char *dptr, char *tptr)
{
    // write down your code here

    for (;*dptr != 0; dptr++) {
        char *d = dptr;
        char *t = tptr;
        while (*d == *t && *t != 0) {
            d++;
            t++;
        }
        if (*t == 0) {
            return dptr;
        }
    }

    return 0;
}

int your_main(char *document, size_t doc_size)
{
    // write down your code here
    char search[MAX_TARGET];
    char *dptr;
    printf("search?");
    fgets(search, MAX_TARGET, stdin);
    chop(search);
    dptr = document;
    while (dptr != 0) {
        dptr = search_string(dptr, search);
        if (dptr == NULL) {
            break;
        }
        highlight_word(document, dptr, search);
        dptr++;
    }

    return 0;
}

int main(int argc, char *argv[]) 
{
    char *document, *fname = DEFAULT_FNAME;
    size_t doc_size;
    int ret_code;

    while (*++argv) fname = *argv;
    document = read_document(fname, &doc_size);
    
    ret_code = your_main(document, doc_size);

    free_document(document);

    return ret_code;
}

char *read_document(const char *fname, size_t *n)
{
    FILE *fp;
    struct stat stat_buf;
    size_t file_size;
    char *buf;

    if ((fp = fopen(fname, "r")) == NULL) {
        perror(fname);
        exit(1);
    }
    if ((fstat(fileno(fp), &stat_buf) == -1)) {
        perror(fname);
        exit(1);
    }
    file_size = stat_buf.st_size;
    if ((buf = (char*)malloc(file_size + 1)) == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    if ((*n = fread(buf, sizeof(char), file_size, fp)) != file_size) {
        if (ferror(fp)) {
            perror(fname);
            exit(1);                 
        }
    }
    fclose(fp);
    buf[*n] = '\0';

    return buf;
}

void free_document(char *buf)
{
    free(buf);
}

void highlight_word(const char *document, const char *dptr, const char *target)
{
    const char *p;

    p = dptr - document < 20 ? document : dptr - 20;
    while (p < dptr) printf("%c", *p++);
    while (p < dptr + strlen(target)) 
        printf("\x1b[4m\x1b[31m%c\x1b[0m\x1b[39m", *p++);
    while (*p != '\0' && p < dptr + strlen(target) + 20) 
        printf("%c", *p++);
    putchar('\n');
}