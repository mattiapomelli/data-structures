#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    Bi_list l = newList();
    char c;
    int n;

    while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case 'f':
                scanf("%d", &n);
                addToFront(l, n);
                break;
            case 't':
                scanf("%d", &n);
                addToTail(l, n);
                break;
            case 'r':
                removeFromFront(l);
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
            case 'o':
                printListReverse(l);
            break;
            case 's':
                printf("Size of the list: %d\n", size(l));
            break;
            case '?':
                if(isEmpty(l)) {
                    printf("List is empty\n");
                } else {
                    printf("List is not empty\n");
                }
            break;
            default:
            break;
        }
    }
}