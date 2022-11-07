// AVL tree creation
// Write a program that implements the AVL tree that satisfies the given conditions.

// Condition
// Until the end (q) command, the insertion (i), the search (s), the print (p), and the command are repeated and performed.
// i <key> : Insert the key into the AVL tree.
// s <key> : Search for the key in the AVL tree.
// p : Print the AVL tree in the order of the preorder traversal.
// q : End the program.

// caution
// 1. It presupposes that there is no overlapping key
// 2. To simplify the problem, It is implemented as having only a key and no element.
// 3. The main function must initialize the empty binary search tree before receiving the command repeatedly.

// hint
// 1. Add height to the node structure
// 2. If an imbalance occurs after the key insertion, the restructuring is performed. restructure are often called rotation. and There are four types, including left and right symmetry.

// example input
// i 44
// i 17 
// i 78 
// i 32 
// i 50 
// i 88 
// i 48 
// i 62 
// s 88 
// p
// q

// example output
// 88
//  44 17 32 78 50 48 62 88

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int key;
    int height;
    struct NODE *lChild, *rChild;
    struct NODE *parent;
} node;

node *root = NULL;

node *treeSearch(node *x, int k) {
    if (x == NULL || k == x->key) {
        return x;
    }
    if (k < x->key) {
        return treeSearch(x->lChild, k);
    } else {
        return treeSearch(x->rChild, k);
    }
}

int isInternal(node *x) {
    return (x->lChild != NULL || x->rChild != NULL);
}

int isExternal(node *x) {
    return (x->lChild == NULL && x->rChild == NULL);
}

void insertItem(int key){
    node *w = treeSearch(root, key);
    if (isItemInTree(key)) {
        return;
    }
    else{
        // expandExternal(w);
        node *z = (node *)malloc(sizeof(node));
        z->key = key;
        z->height = 0;
        z->lChild = NULL;
        z->rChild = NULL;
        z->parent = w;
        if (w == NULL) {
            root = z;
        }
        else if (key < w->key) {
            w->lChild = z;
        }
        else {
            w->rChild = z;
        }

        // restructure
        node *y = z->parent;
        

    }
}
