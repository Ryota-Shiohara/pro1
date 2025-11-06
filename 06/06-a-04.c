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

struct data_t* insert_pos(struct data_t* p, struct data_t* w) {
    struct data_t* pos;
    for (pos = p;pos->fp != p; pos = pos->fp) {
        if (pos->data >= w->data) {
            break;
        }
    }
    return pos;
}

void printasc(struct data_t* p) {
    struct data_t* fp;
    for (fp=p->fp; fp!=p; fp=fp->fp) {
        printf("%d", fp->data);
    }
    printf("\n");
}

void printdsc(struct data_t* p) {
    struct data_t* bp;
    for (bp=p->bp; bp!=p; bp=bp->bp) {
        printf("%d", bp->data);
    }
    printf("\n");
}


int main() {
    int d;
    struct data_t *head, *w, *pos;

    head = init();
    for (;scanf("%d", &d) != EOF;) {
        w = (struct data_t*)malloc(sizeof(struct data_t));
        w->data = d;
        pos = insert_pos(head, w);
        insert(pos, w);
    }

    printasc(head);
    printdsc(head);

    return 0;
}