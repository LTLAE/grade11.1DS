#include <iostream>

#define maxVertex 7

using namespace std;

typedef int vertexData;

struct Edge {
    int vertexNum;
    float weight;
    struct Edge *next;

};

struct Vertex {
    vertexData data;
    Edge *firstEdge;
};

struct Graph {
    Vertex vertexList[maxVertex];
    int edgeCount;
    int vertexCount;
};

void CreateGraph(Graph *&G, const float[maxVertex][maxVertex], int, int);

void DisplayGraph(Graph *G);

void DestroyGraph(Graph *&G);