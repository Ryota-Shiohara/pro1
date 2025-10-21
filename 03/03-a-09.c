#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[5][3] = {
        {2, 3, 5},
        {6, 8, 11},
        {-5, 2, -3},
        {7, 7, 14},
        {-2, -6, 8}
    };
    int i;
    char r;

    for (i=0; i < 5; i++) {
        if (a[i][0] + a[i][1] == a[i][2]) {
            r = 'O';
        } else {
            r = 'X';
        }

        printf("%c %d.  %d +  %d =  %d\n", r, i, a[i][0], a[i][1], a[i][2]);
    }

    return 0;
}