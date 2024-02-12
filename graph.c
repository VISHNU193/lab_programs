#include <stdio.h>
#include <stdlib.h>

#define MAX 20
struct node 				
{
  	int vertex;
  	struct node* next;
};
struct Graph 					
{
  	int totalVertices;
  	int* visited;
  	struct node** adjLists;
};

int queue[MAX];
int front,rear;
front = -1;
rear=-1;

void addq(int v){
    rear=(rear+1)%MAX;
    queue[rear]=v;
}
int deleteq()
{
    front=(front+1)%MAX;
    return queue[front];
}
struct node* createNode(int v) 
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
struct Graph* createGraph(int vertices) 
{
 	struct Graph* graph = malloc(sizeof(struct Graph));
    graph->totalVertices = vertices;
  	graph->adjLists = malloc(vertices * sizeof(struct node*));
  	graph->visited = malloc(vertices * sizeof(int));
  	int i;
  	for (i = 0; i < vertices; i++) {
    		graph->adjLists[i] = NULL;
    		graph->visited[i] = 0;
  	}
  	return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
  	struct node* newNode = createNode(dest);
  	newNode->next = graph->adjLists[src];
  	graph->adjLists[src] = newNode;
  	newNode = createNode(src);
  	newNode->next = graph->adjLists[dest];
  	graph->adjLists[dest] = newNode;
}
void displayGraph(struct Graph* graph) {
  	int v;
  	for (v = 1; v < graph->totalVertices; v++) {
    		struct node* temp = graph->adjLists[v];
    		printf("\n%d =>  ", v);
    		while (temp) {
      		printf("%d, ", temp->vertex);
     		 temp = temp->next;
    }
    printf("\n");
  }
  printf("\n");
}

void DFS(struct Graph* graph, int vertex) 
{
    static int visited[MAX]={0};
  	struct node* adjList = graph->adjLists[vertex];
  	struct node* temp = adjList;
  	visited[vertex] = 1;
  	printf("%d -> ", vertex);
 	 while (temp != NULL) {
   		 int connectedVertex = temp->vertex;
    		if (visited[connectedVertex] == 0) {
      			DFS(graph, connectedVertex);
    	}
    	temp = temp->next;
  }
}

void BFS(struct Graph * graph,int vertex){
    struct node * w;
    printf("%d ->",vertex);
    static int visited[MAX]={0};
    visited[vertex]=1;
    addq(vertex);
    while(front!=rear){
        vertex=deleteq();
        for(w=graph->adjLists[vertex];w;w=w->next)
            if(!visited[w->vertex]){
                printf(" %d ->",w->vertex);
                addq(w->vertex);
                visited[w->vertex]=1;
            }
    }

}

int main() 
{
  	struct Graph* graph = createGraph(8);
  	addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 5);
  	addEdge(graph, 2, 4);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 8);
  	addEdge(graph, 3, 6);
  	addEdge(graph, 3, 7);
    addEdge(graph, 6, 8);
    addEdge(graph, 7, 8);  
    printf("\nThe Adjacency List of the Graph is:");
  	displayGraph(graph);
    printf("\nDFS traversal of the graph: ");
  	DFS(graph,1);
    printf("\nBFS traversal of graph is : ");    
	BFS(graph,1);
  	return 0;
}