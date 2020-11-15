#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue newQueue(int size) {
	Queue q = malloc(sizeof(struct queue));
	
	q -> items = malloc(size * sizeof(int));
	q -> maxsize = size;
	q -> front = 0;
	q -> rear = -1;
	q -> size = 0;

	return q ;
}

int size(Queue pt) {
	return pt -> size;
}

int isEmpty(Queue pt) {
	return !size(pt);
}

int front(Queue pt) {
	if (isEmpty(pt)) {
		printf("Impossible to get front element. Queue is empty");
		exit(EXIT_FAILURE);
	}

	return pt -> items[pt -> front];
}

void enqueue(Queue q, int x) {
	if (size(q) == q -> maxsize) {
		printf("Impossible to add new element. Queue is full");
		exit(EXIT_FAILURE);
	}

	q -> rear = (q -> rear + 1) % q -> maxsize;	
	q -> items[q -> rear] = x;
	q -> size++;
}

void dequeue(Queue q) {
	if (isEmpty(q)) {
		printf("Impossible to remove element. Queue is empty");
		exit(EXIT_FAILURE);
	}

	q -> front = (q -> front + 1) % q -> maxsize;	
	q -> size--;
}

void printQueue(Queue q) {
	int i;
	printf("[");
	if (q -> size > 0) {
		for (i = 0; i < q -> size - 1; i++) {
			printf("%d - ", q -> items[(q -> front + i) % (q -> maxsize) ]);
		}
		printf("%d", q -> items[(q -> front + i) % (q -> maxsize) ]);
	}
	printf("]\n");
}

