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

void Dijkstra(Graph *G, int vertexInput) {
    float distance[maxVertex], path[maxVertex], minDist;
    int newVertex, Generated[maxVertex];
    for (int timer = 0; timer < G->vertexCount; timer++) {
        distance[timer] = G->edges[vertexInput][timer]; //initialize distance and Generated
        Generated[timer] = 0;
        if (G->edges[vertexInput][timer] < INFINITY) path[timer] = vertexInput;  //edge exist
        else path[timer] = -1;  //edge not exist
    }
    Generated[vertexInput] = 1; //add vertex into Generated
    path[vertexInput] = vertexInput;
    for (int timer = 0; timer < G->vertexCount-1; timer++) {
        minDist = INFINITY; //record minimal distance
        for (int edgeCount = 0; edgeCount < G->vertexCount; edgeCount++) {
            if (Generated[edgeCount] == 0 & distance[edgeCount] < minDist) {
                newVertex = edgeCount;
                minDist = distance[edgeCount];
            }
        }
        Generated[newVertex] = 1;   //add newVertex into Generated
        for (int edgeCount = 0; edgeCount < G->vertexCount; edgeCount++) {  //reset vertex if necessary
            if (Generated[edgeCount] == 0 && G->edges[newVertex][edgeCount] < INFINITY && distance[newVertex] + G->edges[newVertex][edgeCount] < distance[edgeCount]) {
                distance[edgeCount] = distance[newVertex] + G->edges[newVertex][edgeCount];
                path[edgeCount] = newVertex;
            }
        }
    }
    DisplayPath(G, distance, path, Generated, vertexInput);
}

void DisplayPath(Graph *G, float distance[maxVertex], float path[maxVertex], int Generated[maxVertex], int startVertex) {
    float shortPath[maxVertex];
    int SPvertexCount, pathVertex;   //Short Path Vertex Count
    for (int timer = 0; timer < G->vertexCount; timer++) {
        if (Generated[timer] == 1 && timer != startVertex) {
            cout << "Path length from " << startVertex << " to " << timer << " is " << distance[timer] << endl;
            cout << "Path is: ";
            SPvertexCount = 0;  //last point
            shortPath[SPvertexCount] = timer;
            pathVertex = path[timer];
            if (pathVertex == -1) { //path not exist
                cout << "Path not found" << endl;
            } else {
                while (pathVertex != startVertex) {  //path exist
                    SPvertexCount++;
                    shortPath[SPvertexCount] = pathVertex;
                    pathVertex = path[pathVertex];
                }
                SPvertexCount++;
                shortPath[SPvertexCount] = startVertex;
                cout << shortPath[SPvertexCount];  //start point
                for (int otherPath = SPvertexCount - 1; otherPath >= 0; otherPath--) cout << shortPath[otherPath];
                cout << endl;
            }
        }
    }
}