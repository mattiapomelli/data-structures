#include <stdio.h>
#include "stack.h"

int main() {
    Stack s = newStack();
    char c;
    int n;

        while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case '+':
                scanf("%d", &n);
                push(s, n);
                break;
            case '-':
                pop(s);
                break;
            case 'e':
                if(isEmpty(s))
                    printf("Stack is empty\n");
                else 
                    printf("Stack is not empty\n");
            break;
            case 't':
                printf("Top element: %d\n", top(s));
            break;
            case 'p':
                printStack(s);
            break;
            case 'd':
                makeEmpty(s);
            break;
            default:
            break;
        }
    }

    return 0;
}