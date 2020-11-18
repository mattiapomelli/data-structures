#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define N 10

typedef struct stack *Stack;

Stack newStack();

bool isEmpty(Stack s);

void push(Stack s, int n);

int top(Stack s);

void pop(Stack s);

void printStack(Stack s);

void makeEmpty(Stack s);

int size(Stack s);

#endif