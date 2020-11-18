#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    int value;
    struct node *next;
};

List newList() {
    List l = malloc(sizeof(struct list));
    l -> first = NULL;
    return l;
}

void addToHead(List l, int n) {
    Node new_node = malloc( sizeof( struct node) );
    new_node -> value = n;
    new_node -> next = l -> first;
    l -> first = new_node;  
}

void addToTail(List l, int n) {
    Node new_node;
    new_node = malloc( sizeof( struct node) );
    new_node -> value = n;
    new_node -> next = NULL;
    
    // se la lista e' vuota il nuovo nodo e' la testa della lista
    if(isEmpty(l)) {
        l -> first = new_node;
    } // altrimenti scorri fino alla fine della lista e inserisci il nuovo nodo, la testa della lista rimane invariata
    else {
        Node p = l -> first;
        while(p -> next != NULL)
            p = p -> next;
        p -> next = new_node;
    }
}

void removeFromHead(List l) {
    // se la lista e' vuota non cambiare nulla
    if(isEmpty(l)) return;
    // altrimenti sposta l avanti e libera la memoria al nodo precedente
    Node p = l -> first;
    l -> first = p -> next;
    free(p);
}

void removeFromTail(List l) {
    // se la lista e' vuota non cambiare nulla
    if(isEmpty(l)) return ;

    Node curr = l -> first, prev = NULL;
    while(curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    if(prev == NULL) // nodo da eliminare in testa (la lista ha un solo elemento)
        l -> first = l -> first -> next;
    else
        prev -> next = NULL;
    free(curr);
}

void removeElement(List l, int n) {
    Node curr, prev;
    // trova il nodo da eliminare
    for( curr = l -> first, prev = NULL; curr != NULL && curr -> value != n; prev = curr, curr = curr -> next);

    // nodo non trovato    
    if( curr == NULL) { printf("Element to remove not found\n"); return; }

    if( prev == NULL)   // nodo da eliminare in testa
        l -> first = l -> first -> next;
    else // modifica il nodo precedente in modo che punti al successivo di quello da eliminare
        prev -> next = curr -> next;

    free(curr);
}   

// cerca un elemento e restituisce un puntatore al nodo trovato
Node searchElement(List l, int n) {
    Node p = l -> first;
    while(p != NULL && p -> value != n)
        p = p -> next;
    return p;
}

void printList(List l) {
    Node p = l -> first;
    printf("[");
    if(p != NULL) {
        while(p -> next != NULL) {
            printf("%d, ", p -> value);
            p = p -> next;
        }
        printf("%d", p-> value);
    }
    printf("]\n");
}

void destroyList(List l) {
    Node prev = NULL, curr = l -> first;
    while(curr != NULL) {
        prev = curr;
        curr = curr -> next;
        free(prev);
    }
    l -> first = NULL;
}

int size(List l) {
    Node p = l -> first;
    int count = 0;
    while(p != NULL) {
        p = p -> next;
        count++;
    }
    return count;
}

bool isEmpty(List l) {
    return l -> first == NULL;
}