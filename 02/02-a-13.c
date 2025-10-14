#include<stdio.h>

int main() {
    int era, year, base, end;
    printf("input era name (0 Meiji, 1 Taisho, 2 Showa, 3 Heisei, 4 Reiwa): ");
    scanf("%d", &era);
    printf("input year: ");
    scanf("%d", &year);

    if (era == 0) {
        base = 1867;
        end = 45;
        if (1 <= year && year <= end) {
            printf("Meiji %d is %d\n", year, base + year - 1);
        } else {
            printf("Incorrect year. Meiji is from 1 to %d\n", end);
        }
    } else if (era == 1) {
        base = 1912;
        end = 15;
        if (1 <= year && year <= end) {
            printf("Taisho %d is %d\n", year, base + year - 1);
        } else {
            printf("Incorrect year. Taisho is from 1 to %d\n", end);
        }
    } else if (era == 2) {
        base = 1926;
        end = 64;
        if (1 <= year && year <= end) {
            printf("Showa %d is %d\n", year, base + year - 1);
        } else {
            printf("Incorrect year. Showa is from 1 to %d\n", end);
        }
    } else if (era == 3) {
        base = 1989;
        end = 31;
        if (1 <= year && year <= end) {
            printf("Heisei %d is %d\n", year, base + year - 1);
        } else {
            printf("Incorrect year. Heisei is from 1 to %d\n", end);
        }
    } else if (era == 4) {
        base = 2019;
        printf("Meiji %d is %d\n", year, base + year - 1);
        
    } else {
        printf("Era must be 0, 1, 2, 3, 4");
        return 0;
    }
    
    
    return 0;
}