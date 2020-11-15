#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    Node first= NULL;
    char c;
    int n;

        while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case 'f':
                scanf("%d", &n);
                first = addToHead(first, n);
                break;
            case 't':
                scanf("%d", &n);
                first = addToTail(first, n);
                break;
            case 'r':
                first = removeFromHead(first);
            break;
            case 'w':
                first = removeFromTail(first);
            break;
            case '-':
                scanf("%d", &n);        
                first = removeElement(first, n);
            break;
            case 'x':
                first = destroyList(first);
            break;
            case 'p':
                printList(first);
            break;
            case 'o':
                printListReverse(first);
            break;
            case 's':
                printf("Size of the list: %d\n", size(first));
            break;
            default:
            break;
        }
    }

    return 0;
}

