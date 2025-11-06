#include <stdio.h>
#include <stdlib.h>

struct data {
    struct data *idBp;
    struct data *idFp;
    struct data *aveBp;
    struct data *aveFp;
    int id;
    int math, science, english;
    float average;
};

void insertId(struct data* p, struct data* w) {
    w->idFp = p;
    w->idBp = p->idBp;
    p->idBp->idFp = w;
    p->idBp = w;
}

struct data* insertId_pos(struct data* p, struct data* w) {
    struct data* pos;
    for (pos = p->idFp;pos != p; pos = pos->idFp) {
        if (pos->id >= w->id) {
            break;
        }
    }
    return pos;
}

void insertAve(struct data* p, struct data* w) {
    w->aveFp = p;
    w->aveBp = p->aveBp;
    p->aveBp->aveFp = w;
    p->aveBp = w;
}

struct data* insertAve_pos(struct data* p, struct data* w) {
    struct data* pos;
    for (pos = p->aveFp;pos != p; pos = pos->aveFp) {
        if (pos->average >= w->average) {
            break;
        }
    }
    return pos;
}

void input(struct data* sentinel) {
    struct data *w, *idPos, *avePos;
    int id, math, science, english;
    for (;;) {
        printf("Input ID, Math, Science, English : ");
        scanf("%d%d%d%d", &id, &math, &science, &english);
        if (id < 0) {
            break;
        }
        w = (struct data*)malloc(sizeof(struct data));
        w->id = id;
        w->math = math;
        w->science = science;
        w->english = english;
        w->average = (math + science + english) / 3.0;
        idPos = insertId_pos(sentinel, w);
        insertId(idPos, w);
        avePos = insertAve_pos(sentinel, w);
        insertAve(avePos, w);
    }
}

void printId(struct data* sentinel) {
    struct data* p;
    printf("[ID]\n");
    for (p=sentinel->idFp; p!=sentinel; p=p->idFp) {
        printf("ID : %d, Math : %d, Science : %d, English : %d\n", p->id, p->math, p->science, p->english);
    }
}

void printAve(struct data* sentinel) {
    struct data* p;
    printf("[Average]\n");
    for (p=sentinel->aveFp; p!=sentinel; p=p->aveFp) {
        printf("Average : %f, ID : %d\n", p->average, p->id);
    }
}

int main() {

    struct data sentinel; 
    sentinel.idFp = sentinel.idBp = sentinel.aveFp = sentinel.aveBp = &sentinel; 
    input(&sentinel);
    printId(&sentinel);
    printAve(&sentinel);

    return 0;
}