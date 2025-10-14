#include<stdio.h>

int main() {
    int year;
   
    printf("input year: ");
    scanf("%d", &year);

    if (year < 1867) {
        printf("year must be greater than or equal to 1868\n");
    } else if (year == 1912) {
        printf("Meiji 45, Taisho 1\n");
    } else if (year == 1926) {
        printf("Taisho 15, Showa 1\n");
    } else if (year == 1989) {
        printf("Showa 64, Heisei 1\n");
    } else if (year == 2019) {
        printf("Heisei 31, Reiwa 1\n");
    } else if (1868 < year && year < 1912) {
        printf("Meiji %d\n", year - 1867);
    } else if (1912 < year && year < 1926) {
        printf("Taisho %d\n", year - 1911);
    } else if (1926 < year && year < 1989) {
        printf("Showa %d\n", year - 1925);
    } else if (1989 < year && year < 2019) {
        printf("Heisei %d\n", year - 1988);
    } else {
        printf("Reiwa %d\n", year - 2018);
    }

    return 0;

}