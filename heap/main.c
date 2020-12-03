#include <stdio.h>
#include "heap.h"

int main() {
    Pqueue q = pqueue_new(6);
    pqueue_insert(q, new_item(4));
    pqueue_insert(q, new_item(5));
    pqueue_insert(q, new_item(7));
    pqueue_insert(q, new_item(3));
    pqueue_insert(q, new_item(8));
    pqueue_insert(q, new_item(10));
    print_pqueue(q);
    printf("Lunghezza: %d \n", pqueue_length(q));
    printf("Minimo: %d \n", key(pqueue_min(q)));

    pqueue_removeItem(q, 2);
    print_pqueue(q);
    printf("Lunghezza: %d \n", pqueue_length(q));
    printf("Minimo: %d \n", key(pqueue_min(q)));

    return 0;
}