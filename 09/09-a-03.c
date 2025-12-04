#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *from, *to;
    int c;
    
    if ((from = fopen("09-a-01.txt", "r")) == NULL) {
        perror("09-a-01.txt");
        exit(1);
    }

    if ((to = fopen("09-a-03.txt", "a+")) == NULL) {
        perror("09-a-03.txt");
        exit(1);
    }

    while ((c = fgetc(from)) != EOF) {
        fputc(c, to);
    }
    fclose(from);
    fclose(to);
    return 0;
}