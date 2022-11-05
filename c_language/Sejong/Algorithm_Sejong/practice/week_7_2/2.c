#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    int key;
    struct NODE *parent;
    struct NODE *lchild;
    struct NODE *rchild;
} node;

int findElement(int k);          
int removeElement(int k);        
int isExternal(node *w);         
int isInternal(node *w);      

void insertItem(int k);          
void printTree(node *w);
void freeTree(node *w);
void expandExternal(node *w);

node *treeSearch(node *w, int k);
node *reduceExternal(node *z);   
node *sibling(node *w);          
node *inOrderSucc(node *w);      

node *v = NULL;

int main()
{
    char text;
    int key, value;

    v = (node *)malloc(sizeof(node));

    v->parent = NULL;
    v->lchild = NULL;
    v->rchild = NULL;

    while (1)
    {
        scanf("%c", &text);

        if (text == 'i')
        {
            scanf("%d", &key);

            insertItem(key);
            getchar();
        }
        else if (text == 'd')
        {
            scanf("%d", &key);

            value = removeElement(key);

            if (value == -1)
            {
                printf("X\n");
            }
            else
            {
                printf("%d\n", value);
            }

            getchar();
        }
        else if (text == 's')
        {
            scanf("%d", &key);

            if (treeSearch(v, key)->key != key)
            {
                printf("X\n");
            }
            else
            {
                printf("%d\n", treeSearch(v, key)->key);
            }

            getchar();
        }
        else if (text == 'p')
        {
            printTree(v);
            printf("\n");
        }
        else if (text == 'q')
        {
            break;
        }
    }
    freeTree(v);

    return 0;
}

int findElement(int k)
{
    node *w = NULL;
    w = treeSearch(v, k);

    if (isInternal(w))
    {
        return -1;
    }
    else
    {
        return w->key;
    }
}

node *treeSearch(node *w, int k)
{
    if (isExternal(w))
    {
        return w;
    }
    if (k == w->key)
    {
        return w;
    }
    else if (k < w->key)
    {
        return treeSearch(w->lchild, k);
    }
    else
    {
        return treeSearch(w->rchild, k);
    }
}

void insertItem(int k)
{
    node *w = NULL;

    w = treeSearch(v, k);

    if (isInternal(w))
    {
        return;
    }
    else
    {
        w->key = k;
        expandExternal(w);
        return;
    }
}

void expandExternal(node *w)
{
    node *leftnode = NULL, *rightnode = NULL;

    leftnode = (node *)malloc(sizeof(node));
    rightnode = (node *)malloc(sizeof(node));

    leftnode->lchild = NULL;
    leftnode->rchild = NULL;
    leftnode->parent = w;

    rightnode->lchild = NULL;
    rightnode->rchild = NULL;
    rightnode->parent = w;

    w->lchild = leftnode;
    w->rchild = rightnode;

    return;
}

int removeElement(int k)
{
    node *w = NULL, *z = NULL, *y = NULL;

    w = treeSearch(v, k);

    if (isExternal(w))
    {
        return -1;
    }

    z = w->lchild;

    if (!isExternal(z))
    {
        z = w->rchild;
    }

    if (isExternal(z))
    {
        reduceExternal(z);
    }
    else
    {
        y = inOrderSucc(w);
        z = y->lchild;
        w->key = y->key;
        reduceExternal(z);
    }

    return k;
}

int isExternal(node *w)
{
    if (w->lchild == NULL & w->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isInternal(node *w)
{
    if (w->lchild != NULL | w->rchild != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *reduceExternal(node *z)
{
    node *w = NULL, *zs = NULL, *g = NULL;

    w = z->parent;
    zs = sibling(z);

    if (w == v)
    {
        v = zs;
        zs->parent = NULL;
    }
    else
    {
        g = w->parent;
        zs->parent = g;
        if (w == g->lchild)
        {
            g->lchild = zs;
        }
        else
        {
            g->rchild = zs;
        }
    }

    free(z);
    free(w);
    return zs;
}

node *sibling(node *w)
{
    if (w == v)
    {
        return NULL;
    }
    if (w->parent->lchild == w)
    {
        return w->parent->rchild;
    }
    else
    {
        return w->parent->lchild;
    }
}

node *inOrderSucc(node *w)
{
    w = w->rchild;

    if (isExternal(w))
    {
        return NULL;
    }
    while (isInternal(w->lchild))
    {
        w = w->lchild;
    }

    return w;
}

void printTree(node *w)
{
    if (isExternal(w))
    {
        return;
    }
    else
    {
        printf(" %d", w->key);
        printTree(w->lchild);
        printTree(w->rchild);
    }
}

void freeTree(node *w)
{
    if (isExternal(w))
    {
        return;
    }
    else
    {
        freeTree(w->lchild);
        freeTree(w->rchild);
        free(w);
    }
}