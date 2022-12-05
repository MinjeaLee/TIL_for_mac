#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MST 알고리즘
// 1. 모든 정점을 포함하는 트리를 하나 생성한다.
// 2. 트리에 포함되지 않은 정점들 중에서 트리에 포함된 정점들과 연결된 간선들 중에서 최소 가중치를 가지는 간선을 찾는다.
// 3. 찾은 간선의 두 정점을 트리에 포함시킨다.
// 4. 2~3번 과정을 반복한다.


typedef struct _NODE
{
	int key;
	int weight;
	struct _NODE *next;
} node;

typedef struct _LIST
{
	node *head;
	node *tail;
} list;

typedef struct _GRAPH
{
	int size;
	list *adjList;
} graph;

typedef struct _EDGE
{
	int u;
	int v;
	int weight;
} edge;

typedef struct _QUEUE
{
	int front;
	int rear;
	int size;
	edge *data;
} queue;

typedef struct _TREE
{
	int key;
	int weight;
	struct _TREE *parent;
	struct _TREE *lChild;
	struct _TREE *rChild;
} tree;

typedef struct _STACK
{
	int top;
	tree *data[100];
} stack;

void initGraph(graph *g, int size);
void initQueue(queue *q);

void insertEdge(graph *g, int u, int v, int weight);

void enqueue(queue *q, edge e);
edge dequeue(queue *q);

void initTree(tree *t, int key, int weight);
void insertTree(tree *t, int key, int weight);

void initStack(stack *s);
void push(stack *s, tree *t);
tree *pop(stack *s);

void printTree(tree *t);

void initGraph(graph *g, int size)
{
	g->size = size;
	g->adjList = (list *)malloc(sizeof(list) * size);

	for (int i = 0; i < size; i++)
	{
		g->adjList[i].head = NULL;
		g->adjList[i].tail = NULL;
	}
}

void initQueue(queue *q)
{
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	q->data = (edge *)malloc(sizeof(edge) * 100);
}

void insertEdge(graph *g, int u, int v, int weight)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->key = v;
	newNode->weight = weight;
	newNode->next = NULL;

	if (g->adjList[u].head == NULL)
	{
		g->adjList[u].head = newNode;
		g->adjList[u].tail = newNode;
	}
	else
	{
		g->adjList[u].tail->next = newNode;
		g->adjList[u].tail = newNode;
	}
}

void enqueue(queue *q, edge e)
{
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % 100;
	q->size++;
}

edge dequeue(queue *q)
{
	edge e = q->data[q->front];
	q->front = (q->front + 1) % 100;
	q->size--;
	return e;
}

void initTree(tree *t, int key, int weight)
{
	t->key = key;
	t->weight = weight;
	t->parent = NULL;
	t->lChild = NULL;
	t->rChild = NULL;
}		

void insertTree(tree *t, int key, int weight)
{
	tree *newTree = (tree *)malloc(sizeof(tree));
	initTree(newTree, key, weight);

	if (t->lChild == NULL)
	{
		t->lChild = newTree;
		newTree->parent = t;
	}
	else if (t->rChild == NULL)
	{
		t->rChild = newTree;
		newTree->parent = t;
	}
}




int main(){
		
	return 0;
}