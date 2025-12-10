#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    FILE *from, *to;
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

    fseek(from, 0, SEEK_END);
    long current_pos = ftell(from) - 1;

    while (current_pos >= 0) {
        fseek(from, current_pos, SEEK_SET);
        int c = fgetc(from);
        if (c == '\n' || current_pos == 0) {
            long line_start_pos;
            if (current_pos == 0) {
                line_start_pos = 0;
            } else {
                line_start_pos = current_pos + 1;
            }
            fseek(from, line_start_pos, SEEK_SET);

            char buffer[80];
            if (fgets(buffer, 80, from) != NULL) {
                fputs(buffer, to);
            }
        }
        current_pos--;
    }
    
    fclose(from);
    fclose(to);
    return 0;
}