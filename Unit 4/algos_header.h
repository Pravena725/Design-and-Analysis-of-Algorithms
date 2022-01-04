#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node 
{
    int id; //vertex id
    int weight; 
    int d; //path distance
    int prev; //vertex id of previous vertex
    struct Node* next;
}Node;

typedef struct Head // Node header
{
    Node* head;
    int prev; //ID of previous vertex in graph 
    int d; //length of shortest path
}Head;


typedef struct Graph
{
    int n;
    Head* graph;
}Graph;

typedef struct Heap
{
    int n;
    Node*heap;
}Heap;

typedef struct Path
{
    Node* head;
    int d; 
}Path;

typedef struct Paths
{
    int n; //no. of vertices
    Path* paths;
}Paths;


Graph* creategraph(int size);
Head insert(Head head, int id, int weight);
Graph* file(void);
Heap* create(int size);
Heap* delete(Heap* h, int* del);
Heap* update(Heap* h);
Node* outgoing(Graph* g, int* visited, int id);
Heap* distance_update(Heap* h, int id, int d);
Graph* Dijkstra(Graph* g, Heap* h);
Node* insert_path(Node* head, int id);
int* reset(int* arr, int size);
void output(Graph* g);