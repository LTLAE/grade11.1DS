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

void DestroyGraph(Graph *&G);

void ClearVisitedData(Graph *&G);

void DFS(Graph *G, int);

void BFS(Graph *G, int);

//Queue from exp_1_3
typedef int DataType;
struct QueueNode {
    DataType data;
    QueueNode *next, *last, *front, *rear;
};

bool InitQueue(QueueNode *&Q);

bool QueueEmpty(QueueNode *Q);

void EnQueue(QueueNode *&Q, DataType item);

void DeQueue(QueueNode *&Q);

//my queue: front -> -> -> rear
//so here is get rear
int GetRear(QueueNode *Q);

void TraverseQueue(QueueNode *Q);

void DestroyQueue(QueueNode *&Q);