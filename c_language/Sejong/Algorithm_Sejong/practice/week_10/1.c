// adjacency list implementation of a graph
// Create a program that expresses the defense weight graph as a adjacent list and prints out the graph information according to the following command.

// There are three commands given to the interactive program, a, m, and q, and each command must be performed as follows.
// a <node number> : Prints both node with <Node Number> and the trunk weight to the node and the node to the node.If there is no vertex A, you do nothing and print -1.
// m a b w : Change the weight of the trunk (a, b) to w.When such trunks do not exist, they create a new trunk (a, b), a weight w. If w = 0, delete the trunk (a, b).If there is no vertex a or b in the graph, you do nothing and print -1.
// q : End the program.

// input example 1
/*
a 2
m 4 2 3
a 2
q
*/
// output example 1
/*
 1 1 3 1
 1 1 3 1 4 3
*/

// input example 2
/*
a 5
m 3 5 0
a 5
a 7
q
*/
// output example 2
/*
 3 4 5 4 6 3
 5 4 6 3 
-1
*/

// no input graph size

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int vertex;
	int weight;
	struct node *next;
} Node;

typedef struct graph {
	int size;
	Node **adjList;
} Graph;

Graph *createGraph(int size);
void addEdge(Graph *graph, int src, int dest, int weight);
void printGraph(Graph *graph);
void printNode(Node *node);
void freeGraph(Graph *graph);

int main() {
	Graph *graph = createGraph(6);
	int size = 0;
	char cmd;
	int src, dest, weight;

	addEdge(graph, 1, 2, 1);
	addEdge(graph, 1, 3, 1);
	addEdge(graph, 1, 4, 1);
	addEdge(graph, 1, 6, 2);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 5, 4);
	addEdge(graph, 5, 5, 4);
	addEdge(graph, 5, 6, 3);
	while (1) {
		scanf("%c", &cmd);
		switch (cmd) {
		case 'a':
			scanf("%d", &src);
			printNode(graph->adjList[src]);
			break;
		case 'm':
			scanf("%d %d %d", &src, &dest, &weight);
			if (weight == 0) {
				Node *node = graph->adjList[src];
				Node *prev = NULL;
				while (node != NULL) {
					if (node->vertex == dest) {
						if (prev == NULL) {
							graph->adjList[src] = node->next;
						}
						else {
							prev->next = node->next;
						}
						free(node);
						break;
					}
					prev = node;
					node = node->next;
				}
			}
			else {
				addEdge(graph, src, dest, weight);
			}
			break;
		case 'q':
			freeGraph(graph);
			return 0;
		}
	}
}

// BFS
void printNode(Node *node) {
	if (node == NULL) {
		printf("-1\n");
		return;
	}
	while (node != NULL) {
		printf("%d %d ", node->vertex, node->weight);
		node = node->next;
	}
	printf("\n");
}

Graph *createGraph(int size) {
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->size = size;
	graph->adjList = (Node **)malloc(sizeof(Node *) * size);
	for (int i = 0; i < size; i++) {
		graph->adjList[i] = NULL;
	}
	return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
	Node *node = graph->adjList[src];
	Node *prev = NULL;
	while (node != NULL) {
		if (node->vertex == dest) {
			node->weight = weight;
			return;
		}
		prev = node;
		node = node->next;
	}
	node = (Node *)malloc(sizeof(Node));
	node->vertex = dest;
	node->weight = weight;
	node->next = NULL;
	if (prev == NULL) {
		graph->adjList[src] = node;
	}
	else {
		prev->next = node;
	}
}

void printGraph(Graph *graph) {
	for (int i = 0; i < graph->size; i++) {
		printf("%d ", i);
		printNode(graph->adjList[i]);
	}
}

void printNode(Node *node) {
	// If there is no vertex A, you do nothing and print -1.
	if (node == NULL) {
		printf("-1\n");
		return;
	}
	while (node != NULL) {
		printf("%d %d ", node->vertex, node->weight);
		node = node->next;
	}
	printf("\n");
}

void freeGraph(Graph *graph) {
	for (int i = 0; i < graph->size; i++) {
		Node *node = graph->adjList[i];
		while (node != NULL) {
			Node *next = node->next;
			free(node);
			node = next;
		}
	}
	free(graph->adjList);
	free(graph);
}

