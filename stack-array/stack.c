#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack newStack() {
    Stack s = malloc( sizeof( struct stack) );
    s -> top = -1;
    return s;
}

void push(Stack s, int n) {
    if(s -> top >= N - 1) {
        printf("Impossible to insert element. Stack is full\n");
		exit(EXIT_FAILURE); 
    }
    s -> top++;
    s -> elements[s -> top] = n;
}

int top(Stack s) {
    if(isEmpty(s)) {
        printf("Impossible to get top element. Stack is empty\n");
		exit(EXIT_FAILURE);     
    }
    return s -> elements[s -> top];
}

void pop(Stack s) {
    if(isEmpty(s)) {
        printf("Impossible to extract element. Stack is empty\n");
		exit(EXIT_FAILURE);     
    }
    s -> top--;
} 

void printStack(Stack s) {
    printf("[");
    int i;
    if(!isEmpty(s)) {
        for(i = 0; i < s -> top; i++)
            printf("%d, ", s -> elements[i]);
        printf("%d", s -> elements[i]);
    }
    printf("]\n");
}

bool isEmpty(Stack s) {
    return s -> top == -1;
}

void makeEmpty(Stack s) {
    s -> top = -1;
}

int size(Stack s) {
    return s -> top + 1;
}