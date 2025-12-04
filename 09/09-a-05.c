#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    FILE *from, *to;
    long start;
    int i, c;
    char *fromName = argv[1];
    char *toName = argv[2];
    
    if ((from = fopen(fromName, "r")) == NULL) {
        perror(fromName);
        exit(1);
    }

    if ((to = fopen(toName, "w+")) == NULL) {
        perror(toName);
        exit(1);
    }

    start = ftell(from);
    fseek(from, 0, SEEK_END);

    while (ftell(from)) {
        while(fgetc(from) != "\n") {
            fseek(from, -1, SEEK_CUR);
        }

        char buffer[80];
        while (fgets(buffer, 80, from) != NULL) {
            fputs(buffer, to);
        }
    }
    
    fclose(from);
    fclose(to);
    return 0;
}