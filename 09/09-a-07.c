#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *fp;
    char *cityName = argv[1];
    char *fileName = "09-a-07.csv";
    char info[256];
    int flg = 0;
    long male[25] = {0};
    long female[25] = {0};
    int i, j;


    
    
    if ((fp = fopen(fileName, "r")) == NULL) {
        perror(fileName);
        exit(1);
    }

    while (fgets(info, 255, fp)!=NULL) {
        char city[16] = {0};
        char sex;
        sscanf(info, "%15[^,\n]", city);
        if (strcmp(city, cityName) == 0) {
            char *p = info;
            flg = 1;
            p += strcspn(p, ",") + 1;
            sex = *p;
            long *counts;
            if (sex == 'M') {
                counts = male;
            } else if (sex == 'F') {
                counts = female;
            } else {
                break;
            }
            char *endp;
            int index = 0;
            while (*p != '\n' && *p != 0) {
                long count = strtol(p, &endp, 10);
                counts[index] = count;
                index++;

                p = endp;
                if (*p != '\n') {
                    p += strcspn(p, ",") + 1;
                }
            }
        }
        continue;
    }

    if (flg==1){
        for (i=21; i>0; i--) {
            int maleCount = male[i];
            int femaleCount = female[i];
            maleCount /= 10000;
            femaleCount /= 10000;
            for (j=0; j<5-maleCount; j++) {
                printf(" ");
            }
            for (j=0; j<maleCount; j++) {
                printf("*");
            }
            if (i==21) {
                printf(" 100+ ");
            } else {
                printf("%2d-%2d", 5*(i-1), 5*(i-1) + 4);
            }
            for (j=0; j<femaleCount; j++) {
                printf("*");
            }
            printf("\n");

        }
    }

    
    
    if (flg == 0) {
        printf("unknown pref (%s)\n", cityName);
    }
    
    fclose(fp);
    return 0;
}