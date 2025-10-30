#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct vec2 {
    float x;
    float y;
};

float get_area(struct vec2 v1, struct vec2 v2) {
    return fabsf(v1.x*v2.y-v1.y*v2.x);
}

int main() {
    struct vec2 v1;
    struct vec2 v2;
    printf("input v1.x v1,y: ");
    scanf("%f%f", &v1.x, &v1.y);
    printf("input v2.x v2,y: ");
    scanf("%f%f", &v2.x, &v2.y);
    printf("area = %f\n", get_area(v1, v2));

    return 0;
}