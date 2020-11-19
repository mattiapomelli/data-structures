#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>

typedef char *Key;

struct item {
    Key key;
    int n;
};

typedef struct item *Item;

struct bit_node {
    Item item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Item new_item(Key k, int num );

Bit_node bit_new(Item i);

void bit_inorder(Bit_node p);

void bit_preorder(Bit_node p);

void bit_postorder(Bit_node p);

void bist_insert(Bit_node *r , Item item);

// Cerca un nodo per chiave
Bit_node bist_search(Bit_node p, Key k);

int bist_delete(Bit_node *r, Key k);

// Stampa a Sommario: si fa una visita in preorder stampando i nodi con gli opportuni rientri
void bit_printassummary(Bit_node p, int spaces);

#endif