#include <iostream>

#define maxVertex 7

using namespace std;

typedef int vertexData;

struct Vertex {
    int no;
    vertexData data;
};

struct Graph {
    Vertex vertexList[maxVertex];
    int edgeCount;
    int vertexCount;
    float edges[maxVertex][maxVertex];
};

void CreateGraph(Graph *&G, const float[maxVertex][maxVertex], int, int);

void DestroyGraph(Graph *&G);

void Dijkstra(Graph *G, int);

void DisplayPath(Graph *G, float[maxVertex], float[maxVertex], int[maxVertex], int);