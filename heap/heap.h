#ifndef HEAP_H
#define HEAP_H

typedef int Item;

typedef struct pqueue * Pqueue ;

// crea una coda di priorità vuota che potrà contenere al massimo n Item 
Pqueue pqueue_new ( int n );

// distrugge la coda di priorità */
void pqueue_destroy ( Pqueue );

// restituisce la lunghezza della coda di priorità
int pqueue_length ( Pqueue );

// inserisce l’Item nella coda di priorità
void pqueue_insert ( Pqueue , Item );

// estrae dalla coda di priorità l’Item con chiave minima
Item pqueue_extractmin ( Pqueue );

// rimuove l'elemento in posizione i
void pqueue_removeItem( Pqueue, int);

// restituisce l’Item con chiave minima nella coda di priorità 
Item pqueue_min ( Pqueue );

void print_pqueue( Pqueue);

#endif