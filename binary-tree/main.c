#include <time.h>
#include "tree.h"

#define N 8

int main() {
    srand(time(NULL));
    int upper = 10, lower = 0, a[N];
    char c;

    for(int i = 0; i < N; i++) {
        a[i] = (rand() % (upper - lower + 1)) + lower;
    }
    Bit_node root = bit_arr2tree(a, N, 0);

    while( ( c = getchar () ) != 'q' ){
        switch(c) {
            case 'a':
                bit_preorder(root);
                printf("\n");
            break;
            case 'b':
                bit_inorder(root);
                printf("\n");
            break;
            case 'c':
                bit_postorder(root);
                printf("\n");
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