#include <iostream>

using namespace std;

typedef int DataType;
struct QueueNode {
    DataType x;
    DataType y;
    DataType lastX;
    DataType lastY;
    QueueNode *next, *last, *front, *rear;
};

bool InitQueue(QueueNode *&Q);

bool QueueEmpty(QueueNode *Q);

void EnQueue(QueueNode *&Q, DataType, DataType, DataType, DataType);

void SlientDeQueue(QueueNode *&Q);

void DeQueue(QueueNode *&Q);

// void TraverseQueue(QueueNode *Q);

void Destroy(QueueNode *&Q);

void FlipQueue(QueueNode *&Q);