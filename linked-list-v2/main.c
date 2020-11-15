#include <stdio.h>
#include "list.h"

int main() {
    List l = newList();
    char c;
    int n;

        while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case 'f':
                scanf("%d", &n);
                addToHead(l, n);
                break;
            case 't':
                scanf("%d", &n);
                addToTail(l, n);
                break;
            case 'r':
                removeFromHead(l);
            break;
            case 'w':
                removeFromTail(l);
            break;
            case '-':
                scanf("%d", &n);        
                removeElement(l, n);
            break;
            case 'x':
                destroyList(l);
            break;
            case 'p':
                printList(l);
            break;
            case 's':
                printf("Size of the list: %d\n", size(l));
            break;
            default:
            break;
        }
    }
    return 0;
}