#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *file;
    char *input = "Student ID: 62409487\nRyota Shiohara";
    int len = strlen(input);
    int i;
    
    if ((file = fopen("09-a-02.txt", "w")) == NULL) {
        perror("09-a-02.txt");
        exit(1);
    }

    
    for (i=0; i<len; i++) {
        fputc(*input, file);
        input++;
    }

    fclose(file);
    return 0;
}