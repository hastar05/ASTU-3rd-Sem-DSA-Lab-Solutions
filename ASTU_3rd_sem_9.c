#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue
{
    int items[SIZE];
    int front;
    int rear;
};

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct node **adjLists;
};

// Protoptypes
struct node *createNode(int);
struct Graph *createGraph(int);
void addEdge(struct Graph *, int, int);
void printGraph(struct Graph *);
struct queue *createQueue();
void enqueue(struct queue *, int);
int dequeue(struct queue *);
int isEmpty(struct queue *);
void DFS(struct Graph *, int);
void BFS(struct Graph *, int);

int main()
{
    struct Graph *graph1 = createGraph(4);
    struct Graph *graph2 = createGraph(4);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 0, 2);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 3);
    printGraph(graph1);
    printf("\n\nDFS:\n ");
    DFS(graph1, 2);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    printf("\n\nBFS:\n ");
    BFS(graph2, 0);
    return 0;
}

void DFS(struct Graph *graph, int vertex)
{
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;
    graph->visited[vertex] = 1;
    printf("%d -> ", vertex);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph *graph, int vertex)
{
    struct queue *q = createQueue();

    graph->visited[vertex] = 1;
    enqueue(q, vertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d -> ", currentVertex);

        struct node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\nAdjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int value)
{
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}