#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
} Graph;

Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    if (!graph)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node *));
    if (!graph->adjLists)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph *graph, int s, int d)
{
    Node *newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        printf("\nVertex %d: ", v);
        Node *temp = graph->adjLists[v];
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Graph *graph = createGraph(numVertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < numEdges; i++)
    {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }

    printf("\nGraph:\n");
    printGraph(graph);

    return 0;
}