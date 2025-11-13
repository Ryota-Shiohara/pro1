#include <stdio.h>
#include <stdlib.h>

int gcd(int nl, int ns) {
    int temp;
    if (nl < ns) {
        temp = nl;
        nl = ns;
        ns = temp;
    }
    
    if (nl % ns == 0) {
        return ns;
    }
    
    return gcd (ns, nl % ns);
    
}

int main() {
    int n1, n2;
    printf("input two positive numbers: ");
    scanf("%d%d", &n1, &n2);
    if (n1 <= 0 || n2 <= 0) {
        printf("must be positive\n");
        exit(1);
    }
    printf("gcd(%d, %d) = %d\n", n1, n2, gcd(n1, n2));

    return 0;
}