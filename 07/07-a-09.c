#include <stdio.h>
#include <stdlib.h>

int stands[200];
int memo[200][200] = {0};

int mincost(int from, int to) {
    int s1, s2;
    if (memo[from][to] != 0) {
        return memo[from][to];
    } else if (from == to) {
        memo[from][to] = 0;
        return 0;
    } else if (to - from == 1) {
        s1 = abs(stands[from] - stands[to]);
        memo[from][to] = s1;
        return s1;
    } else if (to - from == 2) {
        s1 = abs(stands[from] - stands[to - 1]) + abs(stands[from + 1] - stands[to]);
        s2 = abs(stands[from] - stands[to]);
        if (s1 <= s2) {
            memo[from][to] = s1;
            return s1;
        } else {
            memo[from][to] = s2;
            return s2;
        }
    } else {
        s1 = mincost(from, from + 1) + mincost(from + 1, to);
        s2 = mincost(from, from + 2) + mincost(from + 2, to);
        if (s1 <= s2) {
            memo[from][to] = s1;
            return s1;
        } else {
            memo[from][to] = s2;
            return s2;
        }
    }
}

int main() {
    int n, i;
    printf("input # of stands: ");
    scanf("%d", &n);
    for (i=0; i < n; i++) {
        scanf("%d", &stands[i]);
    }
    printf("minimum cost is %d\n", mincost(0, n - 1));

    return 0;
}