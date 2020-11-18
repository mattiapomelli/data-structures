#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

typedef struct node *Node;

Node addToHead(Node l, int n);

Node addToTail(Node l, int n);

Node removeFromHead(Node l);

Node removeFromTail(Node l);

Node removeElement(Node l, int n); 

// cerca un elemento e restituisce un puntatore al nodo trovato
Node searchElement(Node l, int n);

void printList(Node l);

void printListReverse(Node l);

Node destroyList(Node l);

int size(Node l);

#endif