#include <stdio.h>
#include "list.h"

int main() {
    List l = newList();
    char c;
    int n;

        while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case '+':
                scanf("%d", &n);
                addToList(l, n);
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
            case '?':
                scanf("%d", &n);
                Node el = searchElement(l, n);
                if(el != NULL) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
            break;
            default:
            break;
        }
    }
    return 0;
}