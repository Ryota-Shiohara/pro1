#include<stdio.h>

int main() {
    float oz;

    printf("input (oz): ");
    scanf("%f", &oz);

    if (oz * 28.3 <= 1000) {
        printf("%foz is %fg\n", oz, oz * 28.3);
    } else {
        printf("%foz is %fKg\n", oz, oz * 28.3/1000);
    }
    

    return 0;
}