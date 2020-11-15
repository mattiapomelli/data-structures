#include <stdlib.h>
#include <stdio.h>
#include "list.h"

Bi_list newList() {
    Bi_list l = malloc(sizeof(struct bi_list));
    l -> first = NULL;
    l -> last = NULL;
    return l;
}

void addToTail(Bi_list l, int n) {
    // alloca nuovo nodo
    Bi_node new_node;
    new_node = malloc( sizeof(struct bi_node));
    new_node -> value = n;

    // il precedente del nuovo nodo e' l'ultimo elemento della lista
    new_node -> prev = l -> last;
    new_node -> next = NULL;

    // se la lista non e' vuota, modifica next dell'ultimo elemento in modo che punti al nuovo nodo
    if(l -> last != NULL) {
        l -> last -> next = new_node;
    } // lista vuota: first deve puntare al nuovo nodo
    else {
        l -> first = new_node;
    }
    // modifica last in modo che punti al nuovo nodo
    l -> last = new_node;
}

void addToFront(Bi_list l, int n) {
    // alloca nuovo nodo
    Bi_node new_node;
    new_node = malloc( sizeof(struct bi_node));
    new_node -> value = n;

    // il successivo del nuovo nodo e' il primo elemento della lista
    new_node -> prev = NULL;
    new_node -> next = l -> first;

    // se la lista non e' vuota, modifica prev del primo elemento in modo che punti al nuovo nodo
    if(l -> first != NULL) {
        l -> first -> prev = new_node;
    } // lista vuota: last deve puntare al nuovo nodo
    else {
        l -> last = new_node;
    }
    // modifica first in modo che punti al nuovo nodo
    l -> first = new_node;
}

void removeElement(Bi_list l, int n) {
    Bi_node p = l -> first;
    // scorri la lista fino all'elemento da rimuovere
    while(p != NULL && p -> value != n) {
        p = p -> next;
    }

    // elemento da rimuovere non trovato
    if (p == NULL) { printf("Element to remove not found\n"); return; }

    // elemento da rimuovere e' in testa
    if(p -> prev == NULL) {
        p -> next -> prev = NULL;
        l -> first = l -> first -> next;
    } // elemento da rimuovere e' in testa
    else if (p -> next == NULL) {
        p -> prev -> next = NULL;
        l -> last = l -> last -> prev;
    } // elemento da rimuovere e' in mezzo
    else {
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
    }

    free(p);
}

bool isEmpty(Bi_list l) {
    return l -> first == NULL;
}

void removeFromFront(Bi_list l) {
    if(!isEmpty(l)) {
        // sposta first avanti e libera il nodo in testa
        Bi_node p = l -> first;
        l -> first = p -> next;
        free(p);
        // se dopo la rimozione la lista e' vuota
        if (l -> first == NULL) {
            l -> last = NULL;
        } else {
            l -> first -> prev = NULL;
        }
    } else {
        printf("Impossible to remove element, list is empty");
    }
}

void removeFromTail(Bi_list l) {
    if(!isEmpty(l)) {
        // sposta last indietro e libera il nodo in coda
        Bi_node p = l -> last;
        l -> last = p -> prev;
        free(p);
        // se dopo la rimozione la lista e' vuota
        if(l -> last == NULL) {
            l -> first = NULL;
        } else {
            l -> last -> next = NULL;
        }
    } else {
        printf("Impossible to remove element, list is empty");
    }
}

void printList(Bi_list l) {
    Bi_node p = l -> first;
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

void printListReverse(Bi_list l) {
    Bi_node p = l -> last;
    printf("[");
    if(p != NULL) {
        while(p -> prev != NULL) {
            printf("%d, ", p -> value);
            p = p -> prev;
        }
        printf("%d", p-> value);
    }
    printf("]\n");
}

int size(Bi_list l) {
    Bi_node p = l -> first;
    int count = 0;
    while(p != NULL) {
        p = p -> next;
        count++;
    }
    return count;
}

void destroyList(Bi_list l) {
    Bi_node p;
    while(l -> first != NULL) {
        p = l -> first;
        l -> first = l -> first -> next;
        free(p);
    }
    l -> last = NULL;
    return;
}