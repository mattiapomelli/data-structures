#include <stdio.h>
#include "queue.h"

int main() {
	Queue q;
    char c;
    int n;

    printf("Enter max capacity of queue: ");
    scanf("%d\n", &n);
    q = newQueue(n);

    while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case '+':
                scanf("%d", &n);
                enqueue(q, n);
                break;
            case '-':
                dequeue(q);
                break;
            case 's':
                printf("Size of the queue: %d\n", size(q));
            break;
            case 'e':
                if(isEmpty(q))
                    printf("Queue is empty\n");
                else 
                    printf("Queue is not empty\n");
            break;
            case 'f':
                printf("Front element: %d\n", front(q));
            break;
            case 'p':
                printQueue(q);
            break;
            default:
            break;
        }
    }

	return 0;
}