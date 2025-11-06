#include <stdio.h>
#include <stdlib.h>

struct number {
    struct number *prev;
    struct number *next;
    int data;
};

struct number* init() {
    struct number *head;
    head = (struct number*)malloc(sizeof(struct number));
    head->prev = head;
    head->next = head;
    return head;
}

struct number* insert(struct number* previous, int data) {
    struct number* new;
    new = malloc(sizeof(struct number));
    new->next = previous->next;
    new->prev = previous;
    new->data = data;
    new->next->prev = new;
    previous-> next = new;

    return new;

}


int main() {
    int i, data;
    struct number *head, *new, *next, *prev;

    head = init();
    new = head;

    printf("input 5 numbers: \n");
    for (i=0; i<5; i++) {
        scanf("%d", &data);
        new = insert(new, data);
    }

    printf("number list: ");
    for (next = head->next; next != head; next = next->next) {
        printf("%d,", next->data);
    }
    printf("\n");

    printf("number list: ");
    for (prev = head->prev; prev != head; prev = prev->prev) {
        printf("%d,", prev->data);
    }
    printf("\n");

    return 0;
}