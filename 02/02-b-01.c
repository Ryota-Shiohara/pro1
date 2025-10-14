#include<stdio.h>

int main() {
    int by, bm, bd, y, m, d, adult;
    printf("input birth year: ");
    scanf("%d", &by);
    printf("input birth month: ");
    scanf("%d", &bm);
    printf("input birth day: ");
    scanf("%d", &bd);
    printf("input year: ");
    scanf("%d", &y);
    printf("input month: ");
    scanf("%d", &m);
    printf("input day: ");
    scanf("%d", &d);

    if (y < 2022) {
        adult = 20;
    } else if (y > 2022) {
        adult = 18;
    } else if (m < 4) {
        adult = 20;
    } else {
        adult = 18;
    }

    if ((y - by > adult) || ((y - by == adult) && ((m > bm)|| ((m = bm) && (d >= bd))))) {
        printf("legally adult\n");
    } else {
        printf("legally not adult\n");
    }


    return 0;
}