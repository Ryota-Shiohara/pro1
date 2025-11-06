#include <stdio.h>
#include <stdlib.h>

struct data_t {
    struct data_t *bp;
    struct data_t *fp;
    int data;
};

struct data_t* init() {
    struct data_t *head;
    head = (struct data_t*)malloc(sizeof(struct data_t));
    head->bp = head;
    head->fp = head;
    return head;
}

void insert(struct data_t* p, struct data_t* w) {
    w->fp = p;
    w->bp = p->bp;
    p->bp->fp = w;
    p->bp = w;
}

void printall(struct data_t* p) {
    struct data_t* fp;
    printf("\n");
    for (fp=p->fp; fp!=p; fp=fp->fp) {
        printf("[p: %p, bp: %p, fp: %p, data: %d]\n", fp, fp->fp, fp->bp, fp->data);
    }
}


int main() {
    int d;
    struct data_t *head, *w;

    head = init();
    for (;scanf("%d", &d) != EOF;) {
        w = (struct data_t*)malloc(sizeof(struct data_t));
        w->data = d;
        insert(head, w);
    }

    printall(head);

    return 0;
}