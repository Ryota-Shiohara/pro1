#include<stdio.h>

int main() {
    float oz;

    printf("input (oz): ");
    scanf("%f", &oz);

    printf("%foz is %fg\n", oz, oz * 28.3);

    return 0;
}