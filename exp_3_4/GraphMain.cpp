#include "Graph.h"

const float matrixInput [7][7] = {0,28,INFINITY,INFINITY,INFINITY,10,INFINITY,
                                28,0,16,INFINITY,INFINITY,INFINITY,14,
                                INFINITY,16,0,12,INFINITY,INFINITY,INFINITY,
                                INFINITY,INFINITY,12,0,22,INFINITY,18,
                                INFINITY,INFINITY,INFINITY,22,0,25,24,
                                10,INFINITY,INFINITY, INFINITY,25,0,INFINITY,
                                INFINITY,14,INFINITY,18,24,INFINITY,0};
Graph *g1;

int main() {
    CreateGraph(g1,matrixInput,9,7);
    Dijkstra(g1,0);
    DestroyGraph(g1);
}
