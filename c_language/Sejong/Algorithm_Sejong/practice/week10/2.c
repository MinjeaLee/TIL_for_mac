#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

enum VisitMode
{
	Visited,
	NotVisited
};

typedef int ElementType;

typedef struct tagGraph
{
	int **matrix;
	int vertexCount;
} Graph;

Graph *CreateGraph(int max_vertex);
void AddEdge(Graph *graph, int from, int target, int weight);
void deleteEdge(Graph *graph, int from, int target);
int hasEdge(Graph *graph, int from, int target);
void modify(Graph *graph, int vertexNum, int vertexNum2, int weight);
void Print(Graph *g, int num);

int main()
{
	Graph *graph = CreateGraph(6);

	int num;
	char ch;
	int vertex1, vertex2, weight;

	// 간선 추가
	AddEdge(graph, 1, 2, 1);
	AddEdge(graph, 1, 3, 1);
	AddEdge(graph, 1, 4, 1);
	AddEdge(graph, 1, 6, 2);

	AddEdge(graph, 2, 3, 1);

	AddEdge(graph, 3, 5, 4);

	AddEdge(graph, 5, 5, 4);

	AddEdge(graph, 5, 6, 3);

	while (1)
	{
		scanf("%c", &ch);

		if (ch == 'a')
		{ 
			scanf("%d", &num);
			Print(graph, num);
		}
		else if (ch == 'm')
		{
			scanf("%d %d %d", &vertex1, &vertex2, &weight);
			modify(graph, vertex1, vertex2, weight);
		}
		else if (ch == 'q')
		{
			return 0;
		}
		getchar();
	}

	return 0;
}

Graph *CreateGraph(int max_vertex)
{
	int i = 0;
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vertexCount = max_vertex;
	graph->matrix = (int **)malloc(sizeof(int *) * (max_vertex + 1));

	for (i = 0; i <= max_vertex; i++)
	{
		graph->matrix[i] = (int *)malloc(sizeof(int) * (max_vertex + 1));
		memset(graph->matrix[i], 0, sizeof(int) * (max_vertex + 1));
	}
	return graph;
}

void AddEdge(Graph *graph, int from, int target, int weight)
{
	graph->matrix[from][target] = weight;
	graph->matrix[target][from] = weight;
}

void deleteEdge(Graph *graph, int from, int target)
{
	graph->matrix[from][target] = 0;
	graph->matrix[target][from] = 0;
}

int hasEdge(Graph *graph, int from, int target)
{
	if (graph->matrix[from][target])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void modify(Graph *graph, int vertexNum, int vertexNum2, int weight)
{

	if (vertexNum > graph->vertexCount || vertexNum2 > graph->vertexCount || vertexNum < 1 || vertexNum2 < 1)
	{
		printf("-1\n");
		return;
	}

	if (weight == 0)
	{
		deleteEdge(graph, vertexNum, vertexNum2);
	}
	else
	{
		if (hasEdge(graph, vertexNum, vertexNum2))
		{
			graph->matrix[vertexNum][vertexNum2] = weight;
			graph->matrix[vertexNum2][vertexNum] = weight;
		}
		else
		{
			AddEdge(graph, vertexNum, vertexNum2, weight);
		}
	}
}

void Print(Graph *g, int num)
{
	int i;

	if (g->vertexCount < num || num < 1)
	{
		printf("-1\n");
		return;
	}

	for (i = 1; i <= g->vertexCount; i++)

	{

		if (g->matrix[num][i])
		{
			printf(" %d %d", i, g->matrix[num][i]);
		}
	}
	puts("");
}