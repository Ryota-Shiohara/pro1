#include<stdio.h>

int main() {
    float cm;

    printf("input cm: ");
    scanf("%f", &cm);

    printf("%.2fcm is %.2fin\n", cm, cm / 2.54);

    return 0;
}