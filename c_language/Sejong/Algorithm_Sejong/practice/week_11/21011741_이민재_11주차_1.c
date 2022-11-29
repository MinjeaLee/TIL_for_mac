#include <stdio.h>
#include <stdlib.h>

enum VisitMode	// 방문 확인 
{
	Visited,
	NotVisited
};


typedef struct tagVertex
{
	int data; // 데이터
	int visited;	  // 방문 확인
	struct tagVertex *next;		   // 다음 정점
	struct tagEdge *adjacencyList; // 인접 리스트
} Vertex;

typedef struct tagEdge
{
	struct tagEdge *next; // 다음 간선
	Vertex *from;		  // 시작 정점
	Vertex *target;		  // 도착 정점
} Edge;

typedef struct tagGraph
{
	Vertex *vertices; // 정점 리스트
} Graph;

Graph *CreateGraph();							 // 그래프 생성
void initVertex(Vertex *vertex, int vertexSize); // 정점 초기화
Edge *CreateEdge(Vertex *from, Vertex *target);	 // 간선 생성
void AddEdge(Vertex *v, Edge *e);				 // 간선 추가
void AddVertex(Graph *g, Vertex *v);			 // 정점 추가

Graph *CreateGraph()
{ 
	Graph *graph = (Graph *)malloc(sizeof(Graph));  // 그래프 생성
	graph->vertices = NULL; // 정점 리스트 초기화

	return graph;
}

void initVertex(Vertex *vertex, int vertexSize)
{ 
	int i = 0;
	for (i = 1; i <= vertexSize; i++) // 정점 사이즈만큼 반복
	{
		vertex[i].data = i;	// 데이터 초기화
		vertex[i].next = NULL;	// 다음 정점 초기화
		vertex[i].adjacencyList = NULL;	// 인접 리스트 초기화
		vertex[i].visited = NotVisited;	// 방문 확인 초기화
	}
}

Edge *CreateEdge(Vertex *from, Vertex *target)	
{ 
	Edge *edge = (Edge *)malloc(sizeof(Edge));	// 간선 생성
	edge->from = from;	// 시작 정점 설정
	edge->target = target;	// 도착 정점 설정
	edge->next = NULL; // 다음 간선 초기화

	return edge;
}

void AddVertex(Graph *g, Vertex *v)
{ 
	Vertex *vertexList = g->vertices; // 정점 리스트

	if (vertexList == NULL)	// 정점 리스트가 NULL이면
	{
		g->vertices = v;	// 정점 리스트에 정점 추가
	}
	else
	{

		while (vertexList->next != NULL)	
		{
			if (vertexList->data == v->data || vertexList->next->data == v->data) // 정점 리스트에 정점 데이터가 중복되면
			{ 
				return;
			}
			vertexList = vertexList->next;	// 다음 정점으로 이동
		}
		vertexList->next = v;	// 정점 리스트에 다음 정점 v추가
	}
}

void AddEdge(Vertex *vertex, Edge *edge)
{ 

	if (vertex->adjacencyList == NULL)	// 인접 리스트가 NULL이면
	{
		vertex->adjacencyList = edge;	// 인접 리스트에 간선 추가
	}
	else
	{
		Edge *adjacencyList = vertex->adjacencyList;	// 인접 리스트

		while (adjacencyList->next != NULL)	
		{

			if (adjacencyList->target->data > edge->target->data) // 맨 앞에 노드 삽입,인접리스트 next 정점이 크면
			{ 
				edge->next = adjacencyList;
				vertex->adjacencyList = edge;
				return;
			}
			else if (adjacencyList->next->target->data > edge->target->data) // 중간에 노드 삽입, 인접리스트 next next 정점이 크면
			{ 
				edge->next = adjacencyList->next;
				adjacencyList->next = edge;
				return;
			}
			adjacencyList = adjacencyList->next;	// 다음 간선으로 이동
		}

		if (adjacencyList->target->data > edge->target->data) // 맨 뒤에 노드 삽입, 인접리스트 next 정점이 크면
		{ 
			edge->next = adjacencyList;		// 간선 추가
			vertex->adjacencyList = edge;	// 인접 리스트에 간선 추가
			return;					
		}

		adjacencyList->next = edge; // 다음 간선 
	}
}

void DFS(Vertex *startVertex)
{
	startVertex->visited = Visited; // 방문

	Edge *edge = NULL;	

	printf("%d\n", startVertex->data);	// 정점 출력

	edge = startVertex->adjacencyList;	// 인접 리스트

	while (edge != NULL)
	{
		if (edge->target != NULL && edge->target->visited == NotVisited)	// 인접 리스트가 NULL이 아니고 방문하지 않았으면
		{
			DFS(edge->target);	// 재귀호출
		}
		edge = edge->next;	// 다음 간선으로 이동
	}
}

int main()
{
	Graph *graph = CreateGraph();	// 그래프 생성

	int num;
	char ch;
	int vertex1, vertex2;

	int i = 0;
	int vertexSize, edgeSize, startVertex; // 정점개수,간선개수,순회 시작 정점번호
	Vertex *vertex;

	scanf("%d %d %d", &vertexSize, &edgeSize, &startVertex);	// 정점개수,간선개수,순회 시작 정점번호 입력
	vertex = (Vertex *)malloc(sizeof(Vertex) * (vertexSize + 1));	// 정점 동적할당

	initVertex(vertex, vertexSize);	// 정점 초기화

	for (i = 0; i < edgeSize; i++)
	{ 
		scanf("%d %d", &vertex1, &vertex2);	// 간선 입력

		AddVertex(graph, (vertex + vertex1)); // 그래프에 정점 추가
		AddVertex(graph, (vertex + vertex2));

		AddEdge((vertex + vertex1), CreateEdge(vertex + vertex1, vertex + vertex2)); // 간선 추가
		AddEdge((vertex + vertex2), CreateEdge(vertex + vertex2, vertex + vertex1));
	}

	DFS((vertex + startVertex));	// DFS

	return 0;
}
