#include<stdio.h>
#include<stdlib.h>

int main() {
    float f;
    char c;

    float gToO(float);
    float oToG(float);

    printf("input oz (o) or gram (g): ");

    if (scanf("%f%c", &f, &c) != 2) {
        printf("incorrect input\n");
        exit(1);
    }

    if (c == 'g') {
        printf("%fg is %foz\n", f, gToO(f));
    } else if (c == 'o') {
        printf("%foz is %fg\n", f, oToG(f));
    } else {
        printf("incorrect unit\n");
    }

    return 0;
}

float gToO(float g) {
    return g/28.3;
}

float oToG(float o) {
    return o*28.3;
}