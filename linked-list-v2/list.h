#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node *Node;

typedef struct list {
    Node first;
} *List;

List newList();
void addToHead(List l, int n);

void addToTail(List l, int n);

void removeFromHead(List l);

void removeFromTail(List l);

void removeElement(List l, int n); 

// cerca un elemento e restituisce un puntatore al nodo trovato
Node searchElement(List l, int n);

void printList(List l);

void destroyList(List l);

int size(List l);

bool isEmpty(List l);

#endif