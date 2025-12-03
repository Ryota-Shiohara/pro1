/*
   The usage of printf in this code is dangerous. Why?
   Explain here.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 256

int main()
{
    char buf[MAX_BUF];
    fgets(buf, MAX_BUF, stdin);
    printf(buf);

    return 0;
}