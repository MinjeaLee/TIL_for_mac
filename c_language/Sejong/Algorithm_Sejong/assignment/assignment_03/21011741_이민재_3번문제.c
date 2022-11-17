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
int removeElement(int k);		  
void printTree(node *w);		  
void freeTree(node *w);			  
bool isExternal(node *w);		  
bool isInternal(node *w);		 
node *sibling(node *w);			  
node *inOrderSucc(node *w);		 
void expandExternal(node *w);	  
node *reduceExternal(node *z);	 
node *treeSearch(node *w, int k);

void searchAndFixAfterInsertion(node *w);	  
void searchAndFixAfterRemoval(node *w);
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

int findElement(int k)
// 트리에서 k를 찾아서 그 값을 반환한다.
{
	node *w = NULL;
	w = treeSearch(v, k);

	if (isExternal(w))
	{
		return -1;
	}
	else
	{
		return w->key;
	}
}

node *treeSearch(node *w, int k)	// 
{
	if (isExternal(w)) // 외부 노드면 그 노드 반환
	{
		return w;
	}
	if (k == w->key)	// 키가 맞다면 w 반환
	{
		return w;
	}
	else if (k < w->key)
	{
		return treeSearch(w->lChild, k);	// 제귀적으로 처리
	}
	else
	{
		return treeSearch(w->rChild, k);
	}
}

void insertItem(int k)	// k 삽입
{
	node *w = NULL;

	w = treeSearch(v, k);

	if (isInternal(w))
	{
		return;
	}
	else
	{
		w->key = k;	// 키 삽입
		expandExternal(w);	// 외부 노드 확장
		searchAndFixAfterInsertion(w);	// 삽입 후 균형 잡기
		return;
	}
}

void expandExternal(node *w)	// 외부 노드 확장
{
	node *leftnode = NULL, *rightnode = NULL;

	leftnode = (node *)malloc(sizeof(node));
	rightnode = (node *)malloc(sizeof(node));

	// 초기화
	leftnode->lChild = NULL;
	leftnode->rChild = NULL;
	leftnode->parent = w;
	leftnode->height = 0;

	// 초기화
	rightnode->lChild = NULL;
	rightnode->rChild = NULL;
	rightnode->parent = w;
	rightnode->height = 0;

	// 외부 노드 확장
	w->lChild = leftnode;
	w->rChild = rightnode;
	w->height = 1;

	return;
}

int removeElement(int k)
// 트리에서 k 값을 찾아 삭제하고 그 값 반환
{
	node *w = NULL, *z = NULL, *y = NULL, *zs = NULL;

	w = treeSearch(v, k);	// k를 찾는다.

	if (isExternal(w))	// 외부 노드인 경우
	{
		return -1;
	}

	z = w->lChild;	// z는 w의 왼쪽 자식

	if (!isExternal(z))	// 외부 노드 아닌 경우
	{
		z = w->rChild;	// z는 w의 오른쪽 자식
	}

	if (isExternal(z))	// 외부 노드인 경우
	{
		zs = reduceExternal(z);	// 외부 노드 축소
	}
	else
	{
		y = inOrderSucc(w);	// 중위 후속자 찾기
		z = y->lChild;
		w->key = y->key;
		zs = reduceExternal(z);	// 외부 노드 축소
	}

	searchAndFixAfterRemoval(zs->parent);	// 삭제 후 균형 잡기

	return k;
}

bool isExternal(node *w)	
{
	if (w->lChild == NULL & w->rChild == NULL)
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
	if (w->lChild != NULL | w->rChild != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

node *reduceExternal(node *z)	// 외부 노드 축소
{
	node *w = NULL, *zs = NULL, *g = NULL;

	w = z->parent;
	zs = sibling(z);	// z의 형제 노드

	if (w == v)	// w가 루트인 경우
	{
		v = zs;
		zs->parent = NULL;
	}
	else
	{
		g = w->parent;	// g는 w의 부모
		zs->parent = g;	// zs의 부모를 g로 설정
		if (w == g->lChild)	// w가 g의 왼쪽 자식인 경우
		{
			g->lChild = zs;
		}
		else
		{
			g->rChild = zs;
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
	if (w->parent->lChild == w)	// w가 왼쪽 자식인 경우
	{
		return w->parent->rChild;	// 오른쪽 자식 반환
	}
	else
	{
		return w->parent->lChild;
	}
}

node *inOrderSucc(node *w)		// 중위 후속자 찾기
{
	w = w->rChild;

	if (isExternal(w)) // 오른쪽 자식이 외부 노드면 null 반환
	{
		return NULL;	
	}

	while (isInternal(w->lChild))	// w의 왼쪽 자식이 내부 노드인 경우
	{
		w = w->lChild;	// w는 왼쪽 자식으로 이동
	}
	

	return w;	
}

void printTree(node *w)	// 트리 출력
{
	if (isExternal(w))
	{
		return;
	}
	else
	{
		printf(" %d", w->key);
		printTree(w->lChild);
		printTree(w->rChild);
	}
}

void freeTree(node *w)	// 트리 메모리 해제
{
	if (isExternal(w))
	{
		return;
	}
	else
	{
		freeTree(w->lChild);	// 제귀적으로 해결
		freeTree(w->rChild);
		free(w);
	}
}

bool updateHeight(node *w)	// 높이 업데이트
{
	int h;

	// 왼쪽 자식의 높이와 오른쪽 자식의 높이 중 큰 값에 1을 더함
	if (w->lChild->height > w->rChild->height)
	{
		h = w->lChild->height + 1;
	}
	else
	{
		h = w->rChild->height + 1;
	}

	// 높이가 변하지 않았으면 false 반환
	if (h != w->height)
	{
		w->height = h;
		return true;
	}
	else
	{
		return false;
	}
}

bool isBalanced(node *w)	// 균형 여부 반환
{
	// 왼쪽 자식의 높이와 오른쪽 자식의 높이의 차이가 1 이하이면 true 반환
	if ((w->rChild->height <= (w->lChild->height + 1)) && (w->lChild->height <= (w->rChild->height + 1)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 균형 잡기
node *restructure(node *x, node *y, node *z)
{
	node *a = NULL, *b = NULL, *c = NULL;
	node *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	// x, y, z의 순서에 따라 a, b, c 설정
	if ((z->key < y->key) && (y->key < x->key))
	{
		a = z;
		b = y;
		c = x;
		t0 = a->lChild;
		t1 = b->lChild;
		t2 = c->lChild;
		t3 = c->rChild;
	}
	// x, z, y의 순서에 따라 a, b, c 설정
	else if ((x->key < y->key) && (y->key < z->key))
	{
		a = x;
		b = y;
		c = z;
		t0 = a->lChild;
		t1 = a->rChild;
		t2 = b->rChild;
		t3 = c->rChild;
	}
	else if ((z->key < x->key) && (x->key < y->key))
	{
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
		a = y;
		b = x;
		c = z;
		t0 = a->lChild;
		t1 = b->lChild;
		t2 = b->rChild;
		t3 = c->rChild;
	}
	// a, b, c의 부모 설정
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
	// a, b, c의 자식 설정
	a->lChild = t0;
	t0->parent = a;
	a->rChild = t1;
	t1->parent = a;
	updateHeight(a);
	// 높이 업데이트
	c->lChild = t2;
	t2->parent = c;
	c->rChild = t3;
	t3->parent = c;
	updateHeight(c);

	b->lChild = a;
	a->parent = b;
	b->rChild = c;
	c->parent = b;
	updateHeight(b);

	return b;
}

void searchAndFixAfterInsertion(node *w)
// 삽입 후 균형 잡기
{
	node *x = NULL, *y = NULL, *z = NULL;

	w->lChild->height = 0;
	w->rChild->height = 0;
	w->height = 1;

	// w가 루트인 경우 종료
	if (w->parent == NULL)
	{
		return;
	}

	// z w의 부모로 설정
	z = w->parent;
	// z의 높이가 변하지 않은 경우 종료
	while (updateHeight(z) && isBalanced(z))
	{	
		// z가 루트인 경우 종료
		if (z->parent == NULL)
		{
			return;
		}
		// z의 부모로 설정
		z = z->parent;
	}
	// z의 높이가 변한 경우

	if (isBalanced(z))
	{
		return;
	}

	// z의 자식 중 높이가 더 큰 자식을 y로 설정
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
	// 재구성
	restructure(x, y, z);

	return;
}

void searchAndFixAfterRemoval(node *w)	// 삭제 후 균형 잡기
{
	node *x = NULL, *y = NULL, *z = NULL, *a;

	if (w == NULL)
	{
		return;
	}
	z = w;
	// z의 높이가 변하지 않은 경우 종료
	while (updateHeight(z) && isBalanced(z))
	{
		if (z->parent == NULL)
		{
			return;
		}
		z = z->parent;
	}
	
	if (isBalanced(z))
	{
		return;
	}
	// z의 자식 중 높이가 더 큰 자식을 y로 설정
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
	else if (y->lChild->height < y->rChild->height)
	{
		x = y->rChild;
	}
	else
	{
		if (z->lChild == y)
		{
			x = y->lChild;
		}
		else if (z->rChild == y)
		{
			x = y->rChild;
		}
	}
	// 재구성
	a = restructure(x, y, z);
	// 재귀적으로 호출
	searchAndFixAfterRemoval(a->parent);

	return;
}
