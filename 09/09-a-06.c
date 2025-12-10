#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    FILE *fp;
    char *fileName = argv[1];
    int c, word, sentence, flg;
    
    if ((fp = fopen(fileName, "r")) == NULL) {
        perror(fileName);
        exit(1);
    }
    word = 0;
    sentence = 0;
    flg = 1;
    while ((c = fgetc(fp)) != EOF) {
        
        if ((c == '.' || c == '?' || c == '!')){
            sentence++;
            if (flg == 0) {
                word++;
                flg = 1;
            }
        } else if ((c == ' ' || c == '\n' || c == ',' || c == ':' || c == ';' || c == '"')&&flg == 0) {
            word++;
            flg = 1;
        } else if (('a'<=c&&c<='z') || ('A'<=c&&c<='Z') || ('0'<=c&&c<='9') || (c=='`') || (c=='-')) {
            flg = 0;
        } 
    }

    printf("%s contains:\n        %d words and %d sentences\n", fileName, word, sentence);
    
    fclose(fp);
    return 0;
}