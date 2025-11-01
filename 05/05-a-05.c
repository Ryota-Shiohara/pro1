#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    float x;
    float y;
};


int main() {
    struct point p1, p2;
    float a, b, c;

    printf("input p1.x p1.y: ");
    scanf("%f%f", &p1.x, &p1.y);
    printf("input p2.x p2.y: ");
    scanf("%f%f", &p2.x, &p2.y);

    if (p1.x == p2.x && p1.y == p2.y) {
        printf("the same point...\n");
        exit(1);
    }
    
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = p1.x * p2.y - p2.x * p1.y;

    if (a == 0) {
        //なにもしない 
 
    } else if (a == 1) {
        printf("x");
        if (b == 1 || b > 0) {
            printf("+");
        }   
    }else if (a == -1) {
        printf("-x");
        if (b == 1 || b > 0) {
            printf("+");
        }   
    } else {
        printf("%fx", a);
        if (b == 1 || b > 0) {
            printf("+");
        }   
    } 

    if (b == 0) {
        //なにもしない        
    } else if (b == 1) {
        printf("y");
    } else if (b == -1) {
        printf("-y");
    } else if (b > 0) {
        printf("%fy", b);
    } else if (b < 0) {
        printf("-%fy", -b);
    }

    if (c == 0) {
        //なにもしない        
    } else if (c > 0) {
        printf("+%f", c);
    } else if (c < 0) {
        printf("-%f", -c);
    }
        
    printf("=0\n");
    

    return 0;
}