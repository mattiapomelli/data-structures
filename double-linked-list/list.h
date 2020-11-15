#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

struct bi_node {
    int value;
    struct bi_node *next;
    struct bi_node *prev;
};

typedef struct bi_node *Bi_node;

typedef struct bi_list {
    Bi_node first;
    Bi_node last;
} *Bi_list;

Bi_list newList();

void addToTail(Bi_list q, int n);

void addToFront(Bi_list q, int n);

void removeElement(Bi_list q, int n);

bool isEmpty(Bi_list q);

void removeFromFront(Bi_list q);

void removeFromTail(Bi_list q);

void printList(Bi_list q);

void printListReverse(Bi_list q);

int size(Bi_list q);

void destroyList(Bi_list q);

#endif