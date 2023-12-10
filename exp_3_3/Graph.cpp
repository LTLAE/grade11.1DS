#include "Graph.h"

void CreateGraph(Graph *&G, const float input[maxVertex][maxVertex], int edgeCount, int vertexCount) {
    G = new Graph;
    G->edgeCount = edgeCount;
    G->vertexCount = vertexCount;
    //copy input matrix to Graph matrix
    for (int column = 0; column < maxVertex; column++) {
        for (int row = 0; row < maxVertex; row++) {
            G->edges[column][row] = input[column][row];
        }
    }
    //give vertexes NO.
    for (int timer = 0; timer < maxVertex; timer++) {
        G->vertexList[timer].no = timer;
    }
}

void DestroyGraph(Graph *&G) {
    delete G;
}

void Prim(Graph *G, int rootVertexNum) {
    int minWeightVertex = 0, edgesCount = 0;
    float Generated[maxVertex] = {0}, minDistance[maxVertex] = {0}, minWeight = 0;
    for (int timer = 0; timer < G->vertexCount; timer++) {  //initialize Generated and minDistance
        Generated[timer] = G->edges[rootVertexNum][timer];
        minDistance[timer] = rootVertexNum;
    }
    //start
    for (int timer = 0; timer < G->vertexCount - 1; timer++) {  //find edge with minimal distance among all edges connected
        minWeight = INFINITY;
        for (edgesCount = 0; edgesCount < G->vertexCount; edgesCount++) {
            if (Generated[edgesCount] != 0 && Generated[edgesCount] < minWeight) {  //found an edge with minimal distance
                minWeight = Generated[edgesCount];
                minWeightVertex = edgesCount;   //save it in minWeightVertex
            }
        }
        cout << "The weight of edge( " << minDistance[minWeightVertex] << " , " << minWeightVertex << " ) is: " << minWeight << endl;
        Generated[minWeightVertex] = 0; //vertex with min weight have added to Generated
        for (edgesCount = 0; edgesCount < G->vertexCount; edgesCount++) { //
            if (Generated[edgesCount] != 0 && G->edges[minWeightVertex][edgesCount] < Generated[edgesCount]) {  //change newly added vertex in Generated if necessary
                Generated[edgesCount] = G->edges[minWeightVertex][edgesCount];
                minDistance[edgesCount] = minWeightVertex;
            }
        }

    }
}