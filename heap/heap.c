#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

// Per comodita usiamo gli indici della coda di priorita a partire da 1! Ignoriamo la posizione 0

typedef int Key; 

// typedef struct {
//     Key n;
// } Item;

typedef Item *Heap;

struct pqueue {
    Heap h;
    int size, count;
};

// crea una coda di priorità vuota che potrà contenere al massimo n Item 
Pqueue pqueue_new ( int n ) {
    Pqueue q = malloc( sizeof(struct pqueue));
    q -> h = malloc( sizeof(Item) * (n + 1));
    q -> count = 1;
    q -> size = n;
    return q;
}

int father(int i) {
    return i/2;
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i + 1;
}

Key key( Item i) {
    return i;
}

int cmp( Key a, Key b) {
    if(a == b)
        return 0;
    else
        return a < b ? -1 : 1;
}

void swap( Heap h, int i, int j) {
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
}

void heapify_up ( Heap h, int i ) {
    if ( i > 1 ) {
    int j = father (i);
        if ( cmp( key( h[i] ), key( h[j] ) ) < 0 ) {
            swap ( h, i, j );
            heapify_up ( h, j );
        }
    }
}

void heapify_down ( Heap h, int i, int n ) {
    if ( 2*i <= n ) {        // i ha almeno un figlio

        int j;              // indice del figlio di i con chiave minore
        if ( 2*i == n )     // i ha solo il figlio sinistro
            j = 2*i;
        else // i ha due figli
            j = cmp( key( h[2*i] ), key( h[2*i+1] ) ) < 0 ? 2*i : 2*i + 1;
        
        // se l'elemento e' fuori posto, scambio
        if ( cmp( key( h[j] ), key( h[i] ) ) < 0 ) {
            swap ( h, i, j );
            heapify_down ( h, j, n );
        }
    }
}

// distrugge la coda di priorità
void pqueue_destroy ( Pqueue );

// restituisce la lunghezza della coda di priorità
int pqueue_length ( Pqueue q) {
    return q -> count - 1;
}

// inserisce l’Item nella coda di priorità
void pqueue_insert ( Pqueue q, Item i) {
    Heap heap = q -> h;
    heap[q -> count] = i;
    heapify_up(heap, q -> count);
    q -> count++;
}

// estrae dalla coda di priorità l’Item con chiave minima
Item pqueue_extractmin ( Pqueue q) {
    Heap h = q -> h;
    Item root = h[1];
    h[1] = h[--(q -> count)];   // sposta ultimo elemento nella radice ed elimina


    if( cmp(key(h[1]), key(h[left(1)])) > 0 || cmp(key(h[1]), key(h[right(1)])) > 0 )
        heapify_down(h, 1, q -> count);

    return root;
}

// rimuove l'elemento in posizione i
void pqueue_removeItem( Pqueue q, int i) {
    Heap h = q -> h;
    h[i] = h[--(q -> count)];   // sposta ultimo elemento el posto di quello da eliminare

    if( cmp( key(h[i]), key(h[father(i)])) < 0)
        heapify_up(h, i);
    else if( cmp( key(h[i]), key(h[left(i)]) ) > 0 || cmp( key(h[i]), key(h[right(i)]) ) > 0)
        heapify_down(h, i, q -> count);
}

// restituisce l’Item con chiave minima nella coda di priorità 
Item pqueue_min ( Pqueue q ) {
    return q -> h[1];
}

void print_pqueue( Pqueue q ) {
    Heap heap = q -> h;
    for(int i = 1; i < q -> count; i++) {
        printf("%d ", heap[i]);
    }
}