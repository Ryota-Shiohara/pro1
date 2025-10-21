#include<stdio.h>
#include<stdlib.h>

int main() {
    #define MAX_NUM 100
    int a[MAX_NUM];
    int i, j;

    for (i = 0; i < MAX_NUM; i++) {
        a[i] = i + 1;
    }

    a[0] = 0;
    
    for (j = 2; j <= MAX_NUM / 2; j++) {
        if (a[j - 1] == 0) {
            continue;
        } else {
            for (i = j; i < MAX_NUM; i++) {
                if (a[i] % j == 0) {
                    a[i] = 0;
                } else {
                    continue;
                }
            }
        }
        
    }

    for (i = 0; i < MAX_NUM; i++) {
        if (a[i] == 0) {
            continue;
        } else {
            printf("%d   ", a[i]);
        }
    }
    printf("\n");

    return 0;
}