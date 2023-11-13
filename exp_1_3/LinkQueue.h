#include <iostream>

using namespace std;

typedef int DataType;
struct QueueNode {
    DataType data;
    QueueNode *next, *last, *front, *rear;
};

bool InitQueue(QueueNode *&Q);

bool QueueEmpty(QueueNode *Q);

void EnQueue(QueueNode *&Q, DataType item);

void DeQueue(QueueNode *&Q);

void GetFront(QueueNode *Q);

void TraverseQueue(QueueNode *Q);

void Destroy(QueueNode *&Q);

void FlipQueue(QueueNode *&Q);