#include <string.h>
#include "tree.h"

Item new_item(Key k, int num ) {
    Item new_item = malloc( sizeof(struct item));
    new_item -> key = k;
    new_item -> n = num;
    return new_item;
}

Bit_node bit_new(Item i) {
    Bit_node new_node = malloc (sizeof( struct bit_node) );
    new_node -> item = i;
    new_node -> l = NULL;
    new_node -> r = NULL;
    return new_node;
}

int compareKeys(Key k1, Key k2) {
    return strcmp(k1, k2);
}

Key key(Bit_node p) {
    return p ? p -> item -> key : NULL;
}

void printNode(Bit_node p) {
    printf("%s: %d ", p -> item -> key, p -> item -> n);
}

void bit_inorder(Bit_node p) {
    if (p) {
        bit_inorder(p -> l);
        printNode(p);
        bit_inorder(p -> r);
    }
}

void bit_preorder(Bit_node p) {
    if (p) {
        printNode(p);
        bit_preorder(p -> l);
        bit_preorder(p -> r);
    }
} 

void bit_postorder(Bit_node p) {
    if (p) {
        bit_postorder(p -> l);
        bit_postorder(p -> r);
        printNode(p);
    }
}

void bist_insert(Bit_node *r , Item item) {
    // crea un nuovo nodo dall'Item ricevuto
    Bit_node new = bit_new(item), parent = NULL, p = *r;
    Key k = item -> key;
    int res;

    // albero vuoto: il nuovo nodo diventa la radice
    if(p == NULL) { *r = new; return; }

    // cerca la posizione in cui inserire il nodo
    while(p != NULL) {
        parent = p;
        if((res = compareKeys(k, key(p))) == 0) {
            printf("Nodo gia presente");
            return;
        }
        p = res < 0 ? p -> l : p -> r;
    }

    // inserimento nodo
    if ( compareKeys(k, key(parent) ) < 0 )
        parent -> l = new;
    else
        parent -> r = new;
}

// Cerca un nodo per chiave
Bit_node bist_search(Bit_node p, Key k) {
    int res;

    while ( p && (res = compareKeys(k, key(p))) != 0 )
        p = res < 0 ? p -> l : p -> r;

    return p;
}

int bist_delete(Bit_node *r, Key k) {
    // s: nodo che andra' a sostituire il nodo da eliminare
    Bit_node parent = NULL, p = *r, s = NULL;
    int res;

    // cerca il nodo da eliminare. dopo il ciclo -> p: nodo da eliminare, parent: suo nodo padre
    while(p != NULL && (res = compareKeys(k, key(p))) != 0) {
        parent = p;
        p = res < 0 ? p -> l : p -> r;
    }

    if(p == NULL) return -1;      // non esiste un nodo con chiave k

    if (p -> l == NULL && p -> r == NULL )      // p non ha figli
        s = NULL;
    else if(p -> l == NULL || p -> r == NULL)   // p ha solo un figlio
        s = p -> l != NULL ? p -> l : p -> r;
    else {                                      // p ha entrambi i figli
        Bit_node sp = p;    // sp punta al padre del nodo che andra a sostituire p

        s = p -> l;
        while(s -> r) {     // trova il nodo piu a destra nel sottoalbero sinistro di p
            sp = s;
            s = s -> r;
        }

        s -> r = p -> r;    // s avra come nuovo figlio destro il sottoalbero destro di p
        if(sp -> r == s) {  // se s e' figlio destro di sp, allora sp non e' p
            sp -> r = s -> l;
            s -> l = p -> l;
        }
    }

    // sostituisci s a p
    if(p == *r)             // se p e' la radice, s diventa la nuova radice
        *r = s;
    else if(parent -> l == p)
        parent -> l = s;
    else
        parent -> r = s;

    free(p);
    return 0;
}

// Stampa a Sommario: si fa una visita in preorder stampando i nodi con gli opportuni rientri
void bit_printassummary(Bit_node p, int spaces) {
    for(int i = 0; i < spaces; i++)
        printf("  ");

    if(p) {    
        printfprintf("*%s: %d\n", p -> item -> key, p -> item -> n);  
        if(!p -> l && !p -> r) return;   // se il nodo e' una foglia termina senza stampare i figli
        bit_printassummary(p -> l, spaces + 1);
        bit_printassummary(p -> r, spaces + 1);
    } else {
        printf("*\n");
    }
}