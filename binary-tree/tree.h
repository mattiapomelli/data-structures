#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct bit_node *Bit_node;

void bit_inorder(Bit_node p);

void bit_preorder(Bit_node p);

void bit_postorder(Bit_node p);

// per alberi non completi, quindi con alcuni nodi che non hanno figli, bisogna scrivere un vettore che ha dei "buchi"
// delle posizione marcate con un valore speciale
Bit_node bit_arr2tree(int a[], int size, int index);

// Stampa a Sommario: si fa una visita in preorder stampando i nodi con gli opportuni rientri
void bit_printassummary(Bit_node p, int spaces);

#endif