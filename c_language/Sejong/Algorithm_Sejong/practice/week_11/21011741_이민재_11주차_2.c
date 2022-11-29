#include <stdio.h>
#include <stdlib.h>

enum VisitMode	// 방문 확인
{
	NotVisited,
	Visited
};

typedef struct tagGraph
{
	int **matrix;	 // 인접 행렬
	int vertexCount; // 정점 개수
} Graph;

Graph *CreateGraph(int max_vertex);				  // 그래프 생성
void AddEdge(Graph *graph, int from, int target); // 간선 생tjd

Graph *CreateGraph(int max_vertex)
{ 
	int i = 0;
	Graph *graph = (Graph *)malloc(sizeof(Graph));						 // 그래프 생성
	graph->vertexCount = max_vertex;								  	 // 정점 개수 설정
	graph->matrix = (int **)malloc(sizeof(int *) * (max_vertex + 1)); 	// 인접 행렬 생성

	for (i = 0; i <= max_vertex; i++)	// 정점 개수만큼 반복
	{
		graph->matrix[i] = (int *)malloc(sizeof(int) * (max_vertex + 1)); // 인접 행렬 생성, i행 생성
		memset(graph->matrix[i], 0, sizeof(int) * (max_vertex + 1));	  // 인접 행렬 초기화
	}
	return graph;
}

void AddEdge(Graph *graph, int from, int target)
{									
	graph->matrix[from][target] = 1; // 간선 추가
	graph->matrix[target][from] = 1; 
}

void BFS(Graph *graph, int startVertex)
{
	int i = 0;
	int size = graph->vertexCount;
	int *queue; 
	int *visit; 
	int rear = 0, front = 0;

	queue = (int *)malloc(sizeof(int) * size);		 // 큐 배열 동적할당
	visit = (int *)malloc(sizeof(int) * (size + 1));	 // 방문 배열 동적할당

	memset(visit, 0, sizeof(int) * (size + 1)); // 메모리 초기화

	*(visit + startVertex) = Visited; // 시작 정점 방문표시
	printf("%d\n", startVertex);	  // 시작 정점 출력

	queue[rear++] = startVertex; // 시작 정점 큐에 삽입
	while (front < rear)	// 큐가 비어있지 않으면 반복
	{
		startVertex = queue[front++];	// 큐에서 정점 추출
		for (i = 1; i <= graph->vertexCount; i++)	// 정점 개수만큼 반복
		{
			if (graph->matrix[startVertex][i] == 1 && !visit[i])	// 인접 정점이면서 방문하지 않았으면
			{					
				visit[i] = Visited; // 방문 표시
				printf("%d\n", i);	// 정점 출력
				queue[rear++] = i;	// 큐에 삽입
			}
		}
	}
}

int main()
{
	Graph *graph;

	int vertex1, vertex2;

	int vertexSize, edgeSize, startVertex; 
	int i;

	scanf("%d %d %d", &vertexSize, &edgeSize, &startVertex);	// 정점 개수, 간선 개수, 시작 정점 입력

	graph = CreateGraph(vertexSize); //	그래프 생성

	for (i = 0; i < edgeSize; i++)	// 간선 개수만큼 반복
	{
		scanf("%d %d", &vertex1, &vertex2);	// 간선 입력
		AddEdge(graph, vertex1, vertex2);	// 간선 추가
	}

	BFS(graph, startVertex);	// BFS 탐색

	return 0;
}
