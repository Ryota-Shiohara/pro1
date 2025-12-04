#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    FILE *to;
    int i, c;
    
    argv++;
    if ((to = fopen(*argv, "a+")) == NULL) {
        perror(*argv);
        exit(1);
    }
    argv++;

    for (i=0; i<argc-2; i++) {
        FILE *from;
        if ((from = fopen(*argv, "r")) == NULL) {
            perror(*argv);
            exit(1);
        }
        while ((c = fgetc(from)) != EOF) {
            fputc(c, to);
        }
        argv++;
        fclose(from);
    }

    fclose(to);
    return 0;
}