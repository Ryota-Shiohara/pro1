#include<stdio.h>
#include<stdlib.h>


int main() {
    #define TEXT_LEN 14
    char plain_text[TEXT_LEN] = {'k', 'e', 'i', 'o', 'u', 'n', 'i', 'v', 'e', 'r', 's', 'i', 't', 'y'};
    int key, i, c;

    printf("input key [1-25]: ");
    scanf("%d", &key);
    if (1 <= key && key <= 25) {
        for (i=0; i < TEXT_LEN; i++) {
            c = plain_text[i];
            c = (c + key - 97) % 26 + 97;
            printf("%c", c);
        }
        printf("\n");
    } else {
        printf("key should be 1-25\n");
        exit(1);
    }   
    
    return 0;
}