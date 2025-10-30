#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circle {
    float x;
    float y;
    float r;
};

int circle_intersect(struct circle *c1, struct circle *c2) {
    int result;
    float distance_sq, rr_add_sq, rr_sub_sq;
    struct circle *temp;
    
    if (c1->r > c2->r) {
        temp = c1;
        c1 = c2;
        c2 = temp;
    }

    distance_sq = (c1->x - c2->x) * (c1->x - c2->x) + (c1->y - c2->y) * (c1->y - c2->y);
    rr_add_sq = c1->r + c2->r;
    rr_add_sq *= rr_add_sq;

    rr_sub_sq = c2->r - c1->r;
    rr_sub_sq *= rr_sub_sq;


    if (distance_sq == 0 && rr_sub_sq == 0) {
        result = -1;
    } else if (distance_sq < rr_sub_sq) {
        result = 0;
    } else if (distance_sq > rr_add_sq) {
        result = 0;
    } else if (distance_sq == rr_add_sq || distance_sq == rr_sub_sq) {
        result = 1;
    } else if  (rr_sub_sq < distance_sq && distance_sq < rr_add_sq) {
        result = 2;
    }
    return result;
}


int main() {
    struct circle c1, c2;
    int result;

    printf("input c1.x c1.y c1.r: ");
    scanf("%f%f%f", &c1.x, &c1.y, &c1.r);
    printf("input c2.x c2.y c2.r: ");
    scanf("%f%f%f", &c2.x, &c2.y, &c2.r);

    result = circle_intersect(&c1, &c2);
    if (result < 0) {
        printf("# of intersections = infinity\n");
    } else {
        printf("# of intersections = %d\n", result);
    }
    

    return 0;
}