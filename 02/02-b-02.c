#include<stdio.h>

int main() {
    int a, b, c, d;
    
    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);

    c = a/b;
    d = a%b;
    
    if ((a/b) > ((float)a/b)) {
        c = (a/b) - 1;
        d = a - b * c;
    }
    printf("C style:\n%d / %d = %d\n%d / %d = %d\n", a, b, a/b, a, b, a%b);
    printf("python style:\n%d / %d = %d\n%d / %d = %d\n", a, b, c, a, b, d);
    
    return 0;
}