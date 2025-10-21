#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[6][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 2, 1, 1},
    };

    int location[2] = {2, 1};
    int isGaming, input, newX;

    void render(int[6][5], int[2]);
    int moveX(int, int[6][5], int[2]);
    int moveY(int, int[6][5], int[2]);
    int check(int[6][5], int[2]);

    for (isGaming = 0; isGaming == 0;) {
        render(a, location);
        scanf("%d", &input);
        newX = moveX(input, a, location);
        location[1] = moveY(input, a, location);
        location[0] = newX;
        isGaming = check(a, location);
    }

    return 0;
}

void render(int a[6][5], int location[]) {
    int i,j;
    for (i = 1; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            if (location[0] == j && location[1] == i) {
                printf("o");
            } else if (a[i][j] == 0) {
                printf(".");
            } else if (a[i][j] == 1) {
                printf("=");
            } else if (a[i][j] == 2) {
                printf("*");
            }
        }
        printf("\n");
    }
}

int moveX(int input, int a[6][5], int location[2]) {
    if (input == 4 && ((a[location[1]][location[0] - 1] == 0) || (a[location[1]][location[0] - 1] == 2))) {
        return location[0] - 1;
    } else if (input == 6 && ((a[location[1]][location[0] + 1] == 0) || (a[location[1]][location[0] + 1] == 2))) {
        return location[0] + 1;
    } else {
        return location[0];
    }
}

int moveY(int input, int a[6][5], int location[2]) {
    if (input == 8 && ((a[location[1] - 1][location[0]] == 0) || (a[location[1] - 1][location[0]] == 2))) {
        return location[1] - 1;
    } else if (input == 5 && ((a[location[1] + 1][location[0]] == 0) || (a[location[1] + 1][location[0]] == 2))) {
        return location[1] + 1;
    } else {
        return location[1];
    }
}

int check(int a[6][5], int location[2]) {
    if (a[location[1]][location[0]] == 2) {
        render(a, location);
        printf("GOAL!\n");
        return 1;
    }
    return 0;
}

