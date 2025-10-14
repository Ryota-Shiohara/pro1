#include <stdio.h> 
#include <stdlib.h> 
 
/* write down the answer here. 
    Cではfloat演算をするときに2進数で計算している。
    浮動小数点表示で足し算を繰り返すと誤差が蓄積していき、結果的に0.1を１０回足したものと1.0の値が異なるということである。
    printf("x = %.15f\n", x); に変更して出力すると、x = 1.000000119209290と出力され、たしかに値が異なっている。

*/ 
 
int main() 
{ 
    int i; 
    float x = 0.0; 
 
    for (i = 0; i < 10; i++) 
        x += 0.1;   
    printf("x = %f\n", x); 
 
    if (x == 1.0) { 
        printf("OK!\n"); 
    } else { 
        printf("????\n"); 
    } 
 
    return 0; 
}