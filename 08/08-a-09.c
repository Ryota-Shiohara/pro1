#include <stdio.h>
#include <stdlib.h>


int main() {
    char input;
    printf("Please help me! [y/n] ");
    scanf("%c", &input);
    switch (input)
    {
    case 'y':
    case 'Y':
        printf("Thank you!\n");
        break;
    
    case 'n':
    case 'N':
        printf("Huh?\n");
        break;
    
    default:
    printf("Yes or no!\n");
        break;
    }

    return 0;
}