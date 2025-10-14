#include<stdio.h>

int main() {
    int year, month, day, h;
    printf("input year: ");
    scanf("%d", &year);
    printf("input month: ");
    scanf("%d", &month);
    printf("input day: ");
    scanf("%d", &day);
    
    h = (year + (year/4) - (year/100) + (year/400) + (13*month + 8)/5 + day) % 7;
    printf("h = %d\n", h);
    
    return 0;
}