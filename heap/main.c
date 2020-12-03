#include <stdio.h>
#include "heap.h"

int main() {
    Pqueue q = pqueue_new(6);
    pqueue_insert(q, 4);
    pqueue_insert(q, 5);
    pqueue_insert(q, 7);
    pqueue_insert(q, 3);
    pqueue_insert(q, 8);
    pqueue_insert(q, 10);
    print_pqueue(q);
    printf("Lunghezza: %d \n", pqueue_length(q));
    printf("Minimo: %d \n", pqueue_min(q));

    pqueue_removeItem(q, 2);
    print_pqueue(q);
    printf("Lunghezza: %d \n", pqueue_length(q));
    printf("Minimo: %d \n", pqueue_min(q));

    return 0;
}