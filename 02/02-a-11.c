#include<stdio.h>

int main() {
    int h1, m1, h2, m2, hr, mr;
    printf("input H1 (earlier): ");
    scanf("%d", &h1);
    printf("input M1 (earlier): ");
    scanf("%d", &m1);
    printf("input H2 (later): ");
    scanf("%d", &h2);
    printf("input M2 (later): ");
    scanf("%d", &m2);
    
    if (m1 > m2) {
        hr = h2 - h1 - 1;
        mr = m2 + 60 - m1;
    } else {
        hr = h2 - h1;
        mr = m2 - m1;
    }

    if (hr < 10 && mr < 10) {
        printf("0%d:0%d\n", hr, mr);
    } else if (hr < 10) {
        printf("0%d:%d\n", hr, mr);
    } else if (mr < 10) {
        printf("%d:0%d\n", hr, mr);
    } else {
        printf("%d:%d\n", hr, mr);
    }
    
    
    return 0;
}