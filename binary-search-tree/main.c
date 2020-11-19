#include <ctype.h>
#include "tree.h"

// reads a word ignoring white spaces at the beginning
char *read_word() {
    int size = 3, i = 0;
    char *a, s;

    a = malloc(size * sizeof(char));

    do {
        s = getchar();
    } while(isspace(s));

    while(1) {
        s = tolower(s);
        if(!isalpha(s))
            break;
        if( i >= size) {
            size += 2;
            a = realloc(a, size * sizeof(char));
        }

        a[i++] = s;
        s = getchar();
    }
    a[i] = '\0';
    return a;
}

int main() {
    Bit_node root = NULL;
    char c, *a;
    int n;

    while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case '+':
                a = read_word();
                scanf("%d", &n);
                bist_insert(&root, new_item(a, n));
            break;
            case '-':
                a = read_word();
                bist_delete(&root, a);
            break;
            case '?':
                a = read_word();
                Bit_node i = bist_search(root, a);
                if(i)
                    printf("Trovato %d\n", i -> item -> n);
                else
                    printf("Non Trovato\n");
            break;
            case 'p':
                bit_printassummary(root, 0);
            break;
            default:
            break;
        }
    }

    return 0;
}