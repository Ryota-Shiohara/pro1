#include <stdio.h>
#include <stdlib.h>

struct mydate {
    int year;
    int month;
    int day;
};

void printdate(struct mydate mydate) {
    printf("%04d/%02d/%02d\n", mydate.year, mydate.month, mydate.day);
}


int main() {
    struct mydate mydate;
    printf("input year month date: ");
    scanf("%d%d%d", &mydate.year, &mydate.month, &mydate.day);
    printdate(mydate);

    return 0;
}