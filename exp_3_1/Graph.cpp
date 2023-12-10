#include "Graph.h"

void CreateGraph(Graph *&G, const float input[maxVertex][maxVertex], int edgeCount, int vertexCount) {
    G = new Graph;
    //set all firstEdge to NULL
    for (int timer = 0; timer < vertexCount; timer++) G->vertexList[timer].firstEdge = NULL;
    //start connecting edges
    for (int column = 0; column < vertexCount; column++) {
        for (int row = 0; row < vertexCount; row++) {
            if (input[column][row] != 0 && input[column][row] != INFINITY) { //edge not exist
                Edge *createEdge = new Edge;
                createEdge->vertexNum = row;
                createEdge->weight = input[column][row];
                createEdge->next = G->vertexList[column].firstEdge;
                G->vertexList[column].firstEdge = createEdge;
            }
            G->vertexCount = vertexCount;
            G->edgeCount = edgeCount;
        }
    }
}

void DisplayGraph(Graph *G) {
    Edge *scanner = nullptr;
    for (int timer = 0; timer < G->edgeCount; timer++) {
        scanner = G->vertexList[timer].firstEdge;
        cout << timer << '\t';
        while (scanner != NULL) {
            cout << scanner->vertexNum << "[" << scanner->weight << "] -> ";
            scanner = scanner->next;
        }
        cout << "^" << endl;
    }
}

void DestroyGraph(Graph *&G) {
    Edge *last = nullptr, *scanner = nullptr;
    for (int timer = 0; timer < G->vertexCount; timer++) {  //scanner all node links
        last = G->vertexList[timer].firstEdge;
        if (last != NULL) {
            scanner = last->next;
            while (last != NULL) {
                last = nullptr;
                delete last;
                last = scanner;
                if (scanner == NULL) break;
                scanner = scanner->next;
            }
            last = nullptr;
            delete last;
        }
    }
    delete G;
    delete scanner;
}