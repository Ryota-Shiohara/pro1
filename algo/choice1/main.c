#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20 


int n;
int perm[MAX_N];     
bool used[MAX_N + 1]; 


void printPerm() {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

void generate(int depth) {

    if (depth == n) {
        printPerm();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            perm[depth] = i;
            used[i] = true; 
            
            generate(depth + 1); 
            
            used[i] = false; 
        }
    }
}

int main() {
    printf("input int n: ");
    scanf("%d", &n);

    if (n > MAX_N) {
        printf("too big n(max %d )\n", MAX_N);
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        used[i] = false;
    }
    generate(0); 
    return 0;
}