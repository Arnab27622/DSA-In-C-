#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an edge in the graph
typedef struct Edge
{
    int src, dest, weight;
} Edge;

// Define a structure to represent a graph
typedef struct Graph
{
    int V, E;   // V: Number of vertices, E: Number of edges
    Edge *edge; // Array of edges
} Graph;

// Function to create a graph with V vertices and E edges
Graph *createGraph(int V, int E)
{
    // Allocate memory for the graph structure
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (!graph)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->V = V;
    graph->E = E;
    // Allocate memory for the array of edges
    graph->edge = (Edge *)malloc(graph->E * sizeof(Edge));
    return graph;
}

// Function to find set of an element i (uses path compression technique)
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two sets of x and y
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Comparator function used by qsort to compare edges based on weight
int myComp(const void *a, const void *b)
{
    Edge *aEdge = (Edge *)a;
    Edge *bEdge = (Edge *)b;
    return aEdge->weight - bEdge->weight;
}

// Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
void KruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge result[V]; // Store the resultant MST
    int e = 0;      // Index variable for result[]

    // Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // Allocate memory for creating subsets
    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && graph->E > 0)
    {
        // Pick the smallest edge and increment the index for next iteration
        Edge next_edge = graph->edge[0];
        qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
        for (int i = 0; i < graph->E - 1; i++)
        {
            graph->edge[i] = graph->edge[i + 1];
        }
        graph->E--;

        // Find the sets of source and destination vertices
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge doesn't cause cycle, include it in the result and increment the index
        if (x != y)
        {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    // Print the constructed MST
    printf("Edges of MST:\n");
    int minimumCost = 0;
    for (int i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);

    free(parent);
}

int main()
{
    int V, E;
    // Take user input for the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Create the graph with the given number of vertices and edges
    Graph *graph = createGraph(V, E);

    // Take user input for the details of each edge (source, destination, and weight)
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    // Find and print the Minimum Spanning Tree (MST)
    KruskalMST(graph);

    return 0;
}