#include <stdio.h>
#include <stdlib.h>

struct mydate {
    int year;
    int month;
    int day;
};

struct vec3 {
    float x;
    float y;
    float z;
};



int main() {
    printf("char %ld byte\n", sizeof(char));
    printf("int %ld byte\n", sizeof(int));
    printf("float %ld byte\n", sizeof(float));
    printf("struct mydata %ld byte\n", sizeof(struct mydate));
    printf("struct vec3 %ld byte\n", sizeof(struct vec3));

    return 0;
}