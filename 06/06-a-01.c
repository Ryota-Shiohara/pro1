#include <stdio.h>
#include <stdlib.h>

struct number {
    struct number *next;
    int data;
};

struct number* init() {
    return malloc(sizeof(struct number));
}

struct number* insert(struct number* previous, int data) {
    struct number* new;
    new = malloc(sizeof(struct number));
    new->next = NULL;
    new->data = data;
    previous->next = new;

    return new;

}


int main() {
    int i, data;
    struct number *head, *new, *next;

    head = init();
    new = head;

    printf("input 5 numbers: \n");
    for (i=0; i<5; i++) {
        scanf("%d", &data);
        new = insert(new, data);
    }

    printf("number list: ");
    for (next = head->next; next != NULL; next = next->next) {
        printf("%d,", next->data);
    }
    printf("\n");

    return 0;
}