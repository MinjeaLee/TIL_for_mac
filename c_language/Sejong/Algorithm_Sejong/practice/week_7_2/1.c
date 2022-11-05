#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE{
    int key;
    struct NODE *parent;
    struct NODE *lchild, *rchild;
}node;

node *root = NULL;

int findElment(int k); 
int removeElement(int k); // internal node 삭제 가능
int isExternal(node *w);  
int isInternal(node *w);

void insertItem(int k);

node *treeSearch(node *v, int k); 
node *inOrderSucc(node *w); 
node *reduceExternal(node *w);
node *sibling(node *w);



node *treeSearch(node *v, int k){
    if(isExternal(v)) return v;
    if(k == v->key) return v;
    else if(k < v->key) return treeSearch(v->lchild, k);
    else return treeSearch(v->rchild, k);
}

int findElment(int k){
    node *w = treeSearch(root, k);
    if (isExternal(w)) return -1;
    else return w->key;
}

int removeElement(int k){
    // can remove internal node
    node *w = treeSearch(root, k);

    if (isExternal(w)) return -1;
    if(w == NULL) return -1;

    int e = w->key;

    node *z =   w->lchild;

    if (z == NULL) z = w->rchild;
    if(!isExternal(z)) z = w->rchild;
    if(isExternal(z)) reduceExternal(z);

    else{
        node *y = inOrderSucc(w);
        z =  y->lchild;
        w->key = y->key;
        reduceExternal(z);
    }
    return e;
}

/*
int removeElement(node *w, int k){
    node *p = NULL, *z = NULL, *y = NULL;
    p = treeSearch(w, k);
    int e;

    if(isExternal(p)) return -1;

    e = p->key;
    z = p->lChild;

    if(!isExternal(z)) z = p->rChild;
    if(isExternal(z)) reduceExternal(p, z);
    else{
        y = inOrderSucc(p);
        z = y->lChild;
        p->key = y->key;
        reduceExternal(p,z);
    }
*/

node *inOrderSucc(node *w){
    w = w->rchild;
    if (isExternal(w)) return NULL;
    while(isInternal(w->lchild)) w = w->lchild;
    return w;
}

node *reduceExternal(node *z){
    // 중복 제거 
    node *w = z->parent;
    node *zs = sibling(z);

    

    if(w == root){
        root = zs;
        zs->parent = NULL;
    }
    else{
        node *g = w->parent;
        zs->parent = g;
        if(w == g->lchild) g->lchild = zs;
        else g->rchild = zs;
    }
    free(z);
    free(w);
    return zs;
}



// void expandExternal(node *w)
// {
//     node *lChildNode = (node *)malloc(sizeof(node));
//     node *rChildNode = (node *)malloc(sizeof(node));

//     lChildNode->lchild = NULL;
//     lChildNode->rchild = NULL;
//     lChildNode->parent = w;

//     rChildNode->lchild = NULL;
//     rChildNode->rchild = NULL;
//     rChildNode->parent = w;

//     w->lchild = lChildNode;
//     w->rchild = rChildNode;
// }

// void insertItem(int k)
// {
//     node *p = treeSearch(root, k);

//     if (isInternal(p))
//         return;
//     else
//     {
//         p->key = k;
//         expandExternal(p);
//         return;
//     }
// }

void insertItem(int k){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = k;
    newNode->lchild = newNode->rchild = NULL;

    if (root == NULL)
    {
        root = newNode;
        newNode->parent = NULL;
    }
    else
    {
        node *w = root;
        node *trail = NULL;
        while (w != NULL)
        {
            trail = w;
            if (k < w->key)
                w = w->lchild;
            else
                w = w->rchild;
        }
        newNode->parent = trail;
        if (k < trail->key)
            trail->lchild = newNode;
        else
            trail->rchild = newNode;
    }
}



int isRoot(node *w){
    if(w->parent == NULL) return 1;
    return 0;
}

int isExternal(node *w){
    if(w->lchild == NULL && w->rchild == NULL) return 1;
    else return 0;
}

int isInternal(node *w){
    if(w->lchild != NULL || w->rchild != NULL) return 1;
    else return 0;
}



// node *inOrderSucc(node *w){
//     w = w->rchild;
//     while(w->lchild != NULL){
//         w = w->lchild;
//     }
//     return w;
// }

node *sibling(node *w){
    node *p = w->parent;
    if (w == root) return NULL;
    if (w == p->lchild) return p->rchild;
    else return p->lchild;
}

// pre-order
void preorder(node *w){
    if(w != NULL){
        printf(" %d", w->key);
        preorder(w->lchild);
        preorder(w->rchild);
    }
}

int main(){
    char command;
    int key;

    while(1){
        scanf("%c", &command);
        if(command == 'q') break;
        else if(command == 'i'){
            scanf("%d", &key);
            insertItem(key);
        }
        else if(command == 's'){
            scanf("%d", &key);
            int result = findElment(key);
            if(result == -1) printf("X\n");
            else printf("%d\n", result);
        }
        else if(command == 'd'){
            scanf("%d", &key);
            int result = removeElement(key);
            if(result == -1) printf("X\n");
            else printf("%d\n", result);
        }
        else if(command == 'p'){
            preorder(root);
            printf("\n");
        }
    }


    return 0;
}

/*
i 3
i 2
i 7
s 4
i 6
p
i 5
s 6
q
*/

/*
i 9
i 2
i 15
i 1
i 7
i 11
i 5
i 8
i 3
i 4
p
d 2
d 13
p q
*/