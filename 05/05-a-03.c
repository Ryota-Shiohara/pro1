#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct vec3 {
    float x;
    float y;
    float z;
};

float get_volume(struct vec3 v1, struct vec3 v2, struct vec3 v3) {
    return fabsf(
        v1.x*v2.y*v3.z - v1.x*v2.z*v3.y
        + v1.y*v2.z*v3.x - v1.y*v2.x*v3.z
        + v1.z*v2.x*v3.y - v1.z*v2.y*v3.x
    );
}


int main() {
    struct vec3 v1;
    struct vec3 v2;
    struct vec3 v3;
    printf("input v1.x v1.y v1.z: ");
    scanf("%f%f%f", &v1.x, &v1.y, &v1.z);
    printf("input v2.x v2.y v2.z: ");
    scanf("%f%f%f", &v2.x, &v2.y, &v2.z);
    printf("input v3.x v3.y v3.z: ");
    scanf("%f%f%f", &v3.x, &v3.y, &v3.z);
    printf("volume = %f\n", get_volume(v1, v2, v3));

    return 0;
}