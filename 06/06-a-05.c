#include <stdio.h>
#include <stdlib.h>

struct data_t {
    struct data_t *bp;
    struct data_t *fp;
    int key;
    int value;
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

struct data_t* insert_pos(struct data_t* p, int key) {
    struct data_t* pos;
    for (pos = p->fp;pos != p; pos = pos->fp) {
        if (pos->key == key) {
            pos->value++;
            return NULL;
        } else if (pos->key > key) {
            break;
        }
    }
    return pos;
}

void printall(struct data_t* p) {
    struct data_t* fp;
    for (fp=p->fp; fp!=p; fp=fp->fp) {
        printf("[%d] : %d\n", fp->key, fp->value);
    }
}



int main() {
    int d;
    struct data_t *head, *w, *pos;

    head = init();
    for (;scanf("%d", &d) != EOF;) {
        
        pos = insert_pos(head, d);
        if (pos != NULL) {
            w = (struct data_t*)malloc(sizeof(struct data_t));
            w->key = d;
            w->value = 1;
            insert(pos, w);
        }
        
    }

    printall(head);

    return 0;
}