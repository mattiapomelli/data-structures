#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

// Per comodita usiamo gli indici della coda di priorita a partire da 1! Ignoriamo la posizione 0

struct item {
    Key key;
};

typedef Item *Heap;

struct pqueue {
    Heap h;
    int size, count;
};

Item new_item(int k) {
    Item item = malloc(sizeof(struct item));
    item -> key = k;
    return item;
} 

// crea una coda di priorità vuota che potrà contenere al massimo n Item 
Pqueue pqueue_new ( int n ) {
    Pqueue q = malloc( sizeof(struct pqueue));
    q -> h = malloc( sizeof(Item) * (n + 1));
    q -> count = 1;
    q -> size = n;  // n + 1
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

Key key( Item item) {
    return item -> key;
}

int cmp( Key a, Key b) {
    if(a == b)
        return 0;
    else
        return a < b ? -1 : 1;
}

void swap( Heap h, int i, int j) {
    Item temp = h[i];
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

    if( q-> count > q -> size) { printf("Impossibile inserire elemento, heap pieno"); return; }

    Heap heap = q -> h;
    heap[q -> count] = i;
    heapify_up(heap, q -> count);
    q -> count++;
}

// estrae dalla coda di priorità l’Item con chiave minima
Item pqueue_extractmin ( Pqueue q) {

    if(q -> count <= 1) { printf("Impossibile estrarre minimo, coda vuota"); return NULL; }

    // TODO: handle if queue is empty or if root has no children
    Heap h = q -> h;
    Item root = h[1];
    h[1] = h[--(q -> count)];   // sposta ultimo elemento nella radice ed elimina


    //if( cmp(key(h[1]), key(h[left(1)])) > 0 || cmp(key(h[1]), key(h[right(1)])) > 0 )
    heapify_down(h, 1, pqueue_length(q));

    return root;
}

// rimuove l'elemento in posizione i
void pqueue_removeItem( Pqueue q, int i) {
    // free item?
    Heap h = q -> h;
    h[i] = h[--(q -> count)];   // sposta ultimo elemento el posto di quello da eliminare

    if( i != 1 && cmp( key(h[i]), key(h[father(i)])) < 0)       // se l'elemento non e' la radice
        heapify_up(h, i);
    else if( cmp( key(h[i]), key(h[left(i)]) ) > 0 || cmp( key(h[i]), key(h[right(i)]) ) > 0)
        heapify_down(h, i,  pqueue_length(q));
}

// restituisce l’Item con chiave minima nella coda di priorità 
Item pqueue_min ( Pqueue q ) {
    return q -> h[1];
}

void pqueue_sort( Item a[], int l, int r) {
    Pqueue q = pqueue_new(r - l + 1);
    for (int i = l; i <= r; i++) {
        pqueue_insert(q, a[i]);
    }
    while(pqueue_length(q) > 0) {
        Item i = pqueue_extractmin(q);
        printf("%d", key(i));
    }
}

void print_pqueue( Pqueue q ) {
    Heap heap = q -> h;
    for(int i = 1; i < q -> count; i++) {
        printf("%d ", key(heap[i]));
    }
    //pqueue_sort(heap, 2, 5);
}



// // Stampa a Sommario: si fa una visita in preorder stampando i nodi con gli opportuni rientri
// void bit_printassummary(Heap p, int spaces) {
//     for(int i = 0; i < spaces; i++)
//         printf("  ");

//     if(p) {    
//         printfprintf("*%s: %d\n", p -> item -> key, p -> item -> n);  
//         //if(!p -> l && !p -> r) return;   // se il nodo e' una foglia termina senza stampare i figli
//         bit_printassummary(p -> l, spaces + 1);
//         bit_printassummary(p -> r, spaces + 1);
//     } else {
//         printf("*\n");
//     }
// }