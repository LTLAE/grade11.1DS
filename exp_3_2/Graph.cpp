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

void DestroyGraph(Graph *&G) {
    Edge *last = nullptr, *scanner = nullptr;
    for (int timer = 0; timer < G->vertexCount; timer++) {  //scan all node links
        last = G->vertexList[timer].firstEdge;
        if (last != NULL) {
            scanner = last->next;
            while (last != NULL) {  //scan one node link
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

void ClearVisitedData(Graph *&G){
    for (int timer = 0; timer < G->vertexCount; timer++){
        G->vertexList[timer].data = 0;
    }
}

void DFS(Graph *G, int startVertex) {
    //DFS start
    Edge *scanner = nullptr;
    int nextVertex;
    cout << startVertex << " ";
    scanner = G->vertexList[startVertex].firstEdge;     //visit start vertex
    G->vertexList[startVertex].data = 1;    //data = 1 as visited
    while (scanner != NULL) {
        nextVertex = scanner->vertexNum;
        if (G->vertexList[nextVertex].data == 0) DFS(G, nextVertex); //if not visited, visit it
        scanner = scanner->next;
    }
    delete scanner;
}

void BFS(Graph *G, int startVertex) {
    //BFS start
    Edge *scanner = nullptr;
    int nextVertex;
    QueueNode *BFSQueue = nullptr;
    InitQueue(BFSQueue);
    cout << startVertex << " ";
    G->vertexList[startVertex].data = 1;    //data = 1 as visited
    EnQueue(BFSQueue, startVertex);
    while (QueueEmpty(BFSQueue) == 0) {
        DeQueue(BFSQueue);
        nextVertex = GetRear(BFSQueue);
        scanner = G->vertexList[nextVertex].firstEdge;
        while (scanner != NULL) {   //traverse all vertexes of vertexList[startVertex]
            if (G->vertexList[scanner->vertexNum].data == 0) {  //not visited
                cout << scanner->vertexNum << " ";
                G->vertexList[scanner->vertexNum].data = 1;
                EnQueue(BFSQueue,scanner->vertexNum);
            }
            scanner = scanner->next;
        }
    }
}

bool InitQueue(QueueNode *&Q) {
    Q = new QueueNode;
    if (Q == NULL) {
        cout << "Initialization failed." << endl;
        return false;
    }
    Q->next = NULL;
    Q->front = Q;
    Q->rear = Q;
    return true;
}

bool QueueEmpty(QueueNode *Q) {
    return Q->next == NULL;
}

void EnQueue(QueueNode *&Q, DataType item) {
    if (QueueEmpty(Q) == 1) {   //if queue empty
        Q->next = new QueueNode;
        Q->next->last = Q;
        Q->next->data = item;
        Q->front = Q->next;
        Q->rear = Q->next;
        return;
    } else {
        QueueNode *connect;
        connect = Q->next;
        Q->next = new QueueNode;
        Q->next->last = Q;
        Q->next->next = connect;
        connect->last = Q->next;
        Q->front = Q->next;
        Q->next->data = item;
        connect = nullptr;
        delete connect;
    }
}

void DeQueue(QueueNode *&Q) {
    if (QueueEmpty(Q) == 1) {   //if queue is empty
        cout << "The queue is already empty!" << endl;
        return;
    }

    QueueNode *output = nullptr;
    if (Q->next->next == NULL) {   //check if only one node in queue
        Q->front = Q; //reposition front to head
    }
    output = Q->rear;
    Q->rear = Q->rear->last;    //you know after some well-organized structures
    Q->rear->next = NULL;
    delete output;
    return;
}

int GetRear(QueueNode *Q) {
    return Q->rear->data;
}

void TraverseQueue(QueueNode *Q) {
    QueueNode *scanner = Q->next;
    for (cout << "Start outputting data" << endl; scanner->next != NULL; scanner = scanner->next) {
        cout << scanner->data << endl;
    }
    cout << scanner->data << endl;  //last node
    cout << "All data was shown." << endl;
    scanner = nullptr;
    delete scanner;
}

void DestroyQueue(QueueNode *&Q) {
    QueueNode *scanner = nullptr, *del = nullptr;
    for (scanner = Q; scanner->next != NULL; delete del) {
        del = scanner;
        scanner = scanner->next;
    }
    delete scanner, Q->front, Q->rear; //last node;
}