#include "tree.h"

struct bit_node {
    int item;
    struct bit_node *left, *right;
};

void printNode(Bit_node p) {
    printf("%d ", p -> item);
}

void bit_inorder(Bit_node p) {
    if (p) {
        bit_inorder(p -> left);
        printNode(p);
        bit_inorder(p -> right);
    }
}

void bit_preorder(Bit_node p) {
    if (p) {
        printNode(p);
        bit_preorder(p -> left);
        bit_preorder(p -> right);
    }
} 

void bit_postorder(Bit_node p) {
    if (p) {
        bit_postorder(p -> left);
        bit_postorder(p -> right);
        printNode(p);
    }
}

// per alberi non completi, quindi con alcuni nodi che non hanno figli, bisogna scrivere un vettore che ha dei "buchi"
// delle posizione marcate con un valore speciale
Bit_node bit_arr2tree(int a[], int size, int index) {
    if (index < size) {
        Bit_node r = malloc (sizeof( struct bit_node) );
        r -> item = a[index];
        r -> left = bit_arr2tree(a, size, index*2 + 1);
        r -> right = bit_arr2tree(a, size, index*2 + 2);
        return r;
    }
    return NULL;
}

// Stampa a Sommario: si fa una visita in preorder stampando i nodi con gli opportuni rientri
void bit_printassummary(Bit_node p, int spaces) {
    for(int i = 0; i < spaces; i++)
        printf("  ");
    if(p) {    
        printf("*%d\n", p -> item);  
        if(!p -> left && !p -> right) return;   // se il nodo e' una foglia termina senza stampare i figli
        bit_printassummary(p -> left, spaces + 1);
        bit_printassummary(p -> right, spaces + 1);
    } else {
        printf("*\n");
    }
}