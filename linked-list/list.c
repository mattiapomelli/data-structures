#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node addToHead(Node l, int n) {
    Node new_node = malloc( sizeof( struct node) );
    new_node -> value = n;
    new_node -> next = l;
    return new_node;  
}

Node addToTail(Node l, int n) {
    Node new_node;
    new_node = malloc( sizeof( struct node) );
    new_node -> value = n;
    new_node -> next = NULL;
    
    // se la lista e' vuota il nuovo nodo e' la testa della lista
    if(l == NULL) {
        return new_node;
    } // altrimenti scorri fino alla fine della lista e inserisci il nuovo nodo, la testa della lista rimane invariata
    else {
        Node p = l;
        while(l -> next != NULL)
            l = l -> next;
        l -> next = new_node;
        return p;
    }
}

Node removeFromHead(Node l) {
    // se la lista e' vuota non cambiare nulla
    if(l == NULL) return l;
    // altrimenti sposta l avanti e libera la memoria al nodo precedente
    Node p = l;
    l = l -> next;
    free(p);
    return l;
}

Node removeFromTail(Node l) {
    // se la lista e' vuota non cambiare nulla
    if(l == NULL) return l;

    Node curr = l, prev = NULL;
    while(curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    if(prev == NULL) // nodo da eliminare in testa (la lista ha un solo elemento)
        l = l -> next;
    else
        prev -> next = NULL;
    free(curr);
    return l;
}

Node removeElement(Node l, int n) {
    Node curr, prev;
    // trova il nodo da eliminare
    for( curr = l, prev = NULL; curr != NULL && curr -> value != n; prev = curr, curr = curr -> next);
    
    if( curr == NULL)   // nodo non trovato
        return l;
    if( prev == NULL)   // nodo da eliminare in testa
        l = l -> next;
    else // modifica il nodo precedente in modo che punti al successivo di quello da eliminare
        prev -> next = curr -> next;

    free(curr);
    return l;
}   

// cerca un elemento e restituisce un puntatore al nodo trovato
Node searchElement(Node l, int n) {
    while(l != NULL && l -> value != n)
        l = l -> next;
    return l;
}

void printList(Node l) {
    printf("[");
    if(l != NULL) {
        while( l -> next != NULL) {
            printf("%d, ", l -> value);
            l = l -> next;
        }
        printf("%d", l -> value);
    }
    printf("]\n");
}

void printListReverse(Node l) {
    if(l != NULL) {
        printListReverse(l -> next);
        printf("%d ", l -> value);
    }
}

Node destroyList(Node l) {
    Node prev;
    while(l != NULL) {
        prev = l;
        l = l -> next;
        free(prev);
    }
    return NULL;
}

int size(Node l) {
    int count = 0;
    while( l != NULL) {
        l = l -> next;
        count++;
    }
    return count;
}