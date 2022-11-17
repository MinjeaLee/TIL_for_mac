#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _TREENODE
{
    struct _TREENODE *lChild;
    struct _TREENODE *rChild;
    struct _TREENODE *parent;
    int key;
    int height
} node;

int findElement(int k);                       
void insertItem(int k);                       
void printTree(node *w);                      
void freeTree(node *w);                       
bool isExternal(node *w);                     
bool isInternal(node *w);                     
node *sibling(node *w);                       
void expandExternal(node *w);                 
node *treeSearch(node *w, int k);             
void searchAndFixAfterInsertion(node *w);     
bool updateHeight(node *w);                   
bool isBalanced(node *w);                     
node *restructure(node *x, node *y, node *z); 

node *v = NULL;

int main()
{
    char text;
    int key, value;

    v = (node *)malloc(sizeof(node));

    v->parent = NULL;
    v->lChild = NULL;
    v->rChild = NULL;

    while (1)
    {
        scanf("%c", &text);

        if (text == 'i')
        {
            scanf("%d", &key);

            insertItem(key);
            getchar();
        }
        else if (text == 's')
        {
            scanf("%d", &key);

            value = findElement(key);

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

int findElement(int k) // 검색 
{
    node *w = NULL;
    w = treeSearch(v, k); // 트리에서 k값을 가진 노드를 찾는다.

    if (isExternal(w))  // 찾은 노드가 external이면 -1을 반환한다.
    {
        return -1;
    }
    else
    {
        return w->key;  // 찾은 노드가 internal이면 key값을 반환한다.
    }
}

node *treeSearch(node *w, int k)    // 트리에서 k값 가진 노드 찾기
{
    if (isExternal(w))  // w가 외부 노드면 w 반환
    {
        return w;
    }
    if (k == w->key)    // key값이 k와 같으면 w 반환
    {
        return w;
    }
    else if (k < w->key)
    {
        return treeSearch(w->lChild, k);    // ₩->lChild로 재귀호출
    }
    else
    {
        return treeSearch(w->rChild, k);    // ₩->rChild로 재귀호출
    }
}

void insertItem(int k)  // 삽입
{
    node *w = NULL;

    w = treeSearch(v, k);   // 트리에서 k값을 가진 노드를 찾는다.

    if (isInternal(w))  // 찾은 노드가 internal이면 삽입하지 않는다.
    {
        return;
    }
    else
    {
        expandExternal(w);  // 찾은 노드가 external이면 expandExternal을 호출한다.
        w->key = k; // 찾은 노드의 key값을 k로 설정한다.
        searchAndFixAfterInsertion(w);  // 삽입 후 트리의 높이를 조정한다.
    }
}

void expandExternal(node *w)    // 외부 노드 확장
{
    node *leftnode = NULL, *rightnode = NULL;

    leftnode = (node *)malloc(sizeof(node));
    rightnode = (node *)malloc(sizeof(node));

    leftnode->lChild = NULL;    // leftnode의 lChild를 NULL로 설정
    leftnode->rChild = NULL;    // leftnode의 rChild를 NULL로 설정
    leftnode->parent = w;       // leftnode의 parent를 w로 설정
    leftnode->height = 0;       // leftnode의 height를 0으로 설정

    rightnode->lChild = NULL;   // 위와 동일하게 rchild, parent, height 설정
    rightnode->rChild = NULL;
    rightnode->parent = w;
    rightnode->height = 0;

    w->lChild = leftnode;       // w의 lChild를 leftnode로 설정
    w->rChild = rightnode;      // w의 rChild를 rightnode로 설정
    w->height = 1;              // w의 height를 1로 설정

    return;
}

bool isExternal(node *w)
{
    if (w->lChild == NULL & w->rChild == NULL)  // w의 lChild와 rChild가 모두 NULL이면 true 반환
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isInternal(node *w)
{
    if (w->lChild != NULL | w->rChild != NULL)  // w의 lChild나 rChild가 NULL이 아니면 true 반환
    {
        return true;
    }
    else
    {
        return false;
    }
}

node *sibling(node *w)  // 형제 노드 찾기
{
    if (w == v)     // w가 루트 노드면 NULL 반환
    {
        return NULL;
    }
    if (w->parent->lChild == w) // w가 부모 노드의 lChild이면 rChild 반환
    {
        return w->parent->rChild;
    }
    else
    {
        return w->parent->lChild;   // w가 부모 노드의 rChild이면 lChild 반환
    }
}

void printTree(node *w)     // 트리 출력
{
    if (isExternal(w))  // w가 external이면 출력하지 않는다.
    {
        return;
    }
    else
    {
        printTree(w->lChild);   // ₩->lChild로 재귀호출
        printf("%d ", w->key);  // w의 key값 출력
        printTree(w->rChild);   // ₩->rChild로 재귀호출
    }
}

void freeTree(node *w)  // 트리 메모리 해제
{
    if (isExternal(w))  // w가 external이면 해제하지 않는다.
    {
        return;
    }
    else
    {
        freeTree(w->lChild);    // ₩->lChild로 재귀호출
        freeTree(w->rChild);    // ₩->rChild로 재귀호출
        free(w);    // w 해제
    }
}

bool updateHeight(node *w)      // 높이 업데이트
{
    int h;

    if (w->lChild->height > w->rChild->height)  // w의 lChild와 rChild 중 높이가 더 큰 것을 h에 저장
    {
        h = w->lChild->height + 1; 
    }
    else
    {
        h = w->rChild->height + 1;
    }

    if (h != w->height)    // h와 w의 height가 다르면 w의 height를 h로 설정하고 true 반환
    {
        w->height = h;
        return true;
    }
    else
    {
        return false;
    }
}

bool isBalanced(node *w)// 불균형 노드 찾기
{
    if ((w->rChild->height <= (w->lChild->height + 1)) && (w->lChild->height <= (w->rChild->height + 1)))
    // w의 lChild와 rChild의 높이 차이가 1 이하이면 true 반환
    {
        return true;
    }
    else
    {
        return false;
    }
}

node *restructure(node *x, node *y, node *z)
// x, y, z를 기준으로 재구성
{
    node *a = NULL, *b = NULL, *c = NULL;
    node *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

    if ((z->key < y->key) && (y->key < x->key))
    // z < y < x 일때
    {
        // a, b, c, t0, t1, t2, t3 설정
        a = z;
        b = y;
        c = x;
        t0 = a->lChild;
        t1 = b->lChild;
        t2 = c->lChild;
        t3 = c->rChild;
    }
    else if ((x->key < y->key) && (y->key < z->key))
    // x < y < z일때
    {
        // a, b, c, t0, t1, t2, t3 설정
        a = x;
        b = y;
        c = z;
        t0 = a->lChild;
        t1 = a->rChild;
        t2 = b->rChild;
        t3 = c->rChild;
    }
    else if ((z->key < x->key) && (x->key < y->key))
    // z < x < y일떄
    {
        // a, b, c, t0, t1, t2, t3 설정
        a = z;
        b = x;
        c = y;
        t0 = a->lChild;
        t1 = b->lChild;
        t2 = b->rChild;
        t3 = c->rChild;
    }
    else
    {
        // a, b, c, t0, t1, t2, t3 설정
        a = y;
        b = x;
        c = z;
        t0 = a->lChild;
        t1 = b->lChild;
        t2 = b->rChild;
        t3 = c->rChild;
    }


    // a, b, c, t0, t1, t2, t3 설정 후 재구성
    if (z->parent == NULL)
    {
        v = b;
        b->parent = NULL;
    }
    else if (z->parent->lChild == z)
    {
        z->parent->lChild = b;
        b->parent = z->parent;
    }
    else if (z->parent->rChild == z)
    {
        z->parent->rChild = b;
        b->parent = z->parent;
    }

    // a, b, c, t0, t1, t2, t3 설정 후 재구성
    a->lChild = t0;
    t0->parent = a;
    a->rChild = t1;
    t1->parent = a;
    updateHeight(a);
    // a의 높이 업데이트


    c->lChild = t2;
    t2->parent = c;
    c->rChild = t3;
    t3->parent = c;
    updateHeight(c);
    // c의 높이 업데이트

    // a, b, c, t0, t1, t2, t3 설정 후 재구성
    b->lChild = a;
    a->parent = b;
    b->rChild = c;
    c->parent = b;
    updateHeight(b);
    // b의 높이 업데이트

    return b;
}

void searchAndFixAfterInsertion(node *w) // 삽입후 불균형 찾기
{
    node *x = NULL, *y = NULL, *z = NULL;

    // 초기화
    w->lChild->height = 0;
    w->rChild->height = 0;
    w->height = 1;

    if (w->parent == NULL)
    {
        return;
    }

    z = w->parent;  

    // z의 높이 업데이트 후 불균형 노드 찾기
    while (updateHeight(z) && isBalanced(z))
    {
        if (z->parent == NULL)
        {
            return;
        }
        z = z->parent;
    }
    // 불균형일때
    if (isBalanced(z))
    {
        return;
    }

    // x, y, z 설정
    if (z->lChild->height > z->rChild->height)
    {
        y = z->lChild;
    }
    else
    {
        y = z->rChild;
    }
    if (y->lChild->height > y->rChild->height)
    {
        x = y->lChild;
    }
    else
    {
        x = y->rChild;
    }
    // x, y, z 설정 후 재구성
    restructure(x, y, z);

    return;
}