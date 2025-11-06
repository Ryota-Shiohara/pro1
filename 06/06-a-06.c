#include <stdio.h>
#include <stdlib.h>

struct data {
    struct data *bp;
    struct data *fp;
    int value;
};

void push(struct data* sentinel, int n) {
    struct data *w;
    
    w = (struct data*)malloc(sizeof(struct data));
    w->bp = sentinel->bp;
    w->fp = sentinel;
    w->value = n;
    sentinel->bp->fp = w;
    sentinel->bp = w;
    printf("push %d\n", n);
}

int pop_queue(struct data* sentinel) {
    int value;
    value = sentinel->fp->value;
    printf("pop %d(queue)\n", value);
    sentinel->fp = sentinel->fp->fp;
    free(sentinel->fp->bp);
    sentinel->fp->bp = sentinel;
    return value;
}

int pop_stack(struct data* sentinel) {
    int value;
    value = sentinel->bp->value;
    printf("pop %d(stack)\n", value);
    sentinel->bp = sentinel->bp->bp;
    free(sentinel->bp->fp);
    sentinel->bp->fp = sentinel;
    return value;
}


void print_data(struct data* sentinel) {
    struct data* p;
    printf("stored nums : ");
    for (p=sentinel->fp; p!=sentinel; p=p->fp) {
        printf("%d ", p->value);
    }
    printf("\n");
}



int main() 
{ 
int i; 
struct data sentinel; 
sentinel.fp = sentinel.bp = &sentinel; 
push(&sentinel,1); 
print_data(&sentinel); 
push(&sentinel, 2); 
print_data(&sentinel); 
push(&sentinel, 3); 
print_data(&sentinel); 
pop_queue(&sentinel); 
print_data(&sentinel); 
pop_stack(&sentinel); 
print_data(&sentinel); 
return 0; 
} 