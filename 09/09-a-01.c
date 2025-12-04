#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *file;
    int c;
    
    if ((file = fopen("09-a-01.txt", "r")) == NULL) {
        perror("09-a-01.txt");
        exit(1);
    }

    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    return 0;
}