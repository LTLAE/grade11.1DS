#include "LinkQueue.h"

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

void EnQueue(QueueNode *&Q, DataType x, DataType y, DataType lastX, DataType lastY) {
    if (QueueEmpty(Q) == 1) {   //if queue empty
        Q->next = new QueueNode;
        Q->next->last = Q;
        Q->next->x = x;
        Q->next->y = y;
        Q->next->lastX = lastX;
        Q->next->lastY = lastY;
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
        Q->next->x = x;
        Q->next->y = y;
        Q->next->lastX = lastX;
        Q->next->lastY = lastY;
        connect = nullptr;
        delete connect;
    }
}

void SlientDeQueue(QueueNode *&Q) {
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
    cout << "(" << output->x << " , " << output->y <<")" << endl;
    Q->rear = Q->rear->last;    //you know after some well-organized structures
    Q->rear->next = NULL;
    delete output;
    return;
}

/*
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
 */

void Destroy(QueueNode *&Q) {
    QueueNode *scanner = nullptr, *del = nullptr;
    for (scanner = Q; scanner->next != NULL; delete del) {
        del = scanner;
        scanner = scanner->next;
    }
    delete scanner, Q->front, Q->rear; //last node;
}


void FlipQueue(QueueNode *&Q) {  //using enhanced function in exp_1_1
    //when 4+ nodes,three pointers point to three connected nodes then do the following actions
    //s1 -> n1, s2 -> n2, s3 -> n3
    //n2 -> n1, s1 -> n4, then repeat
    //check whether the number of nodes is less than 3
    QueueNode *s1 = Q->next, *s2 = nullptr, *s3 = Q->next;
    //Check if last three nodes.
    if (s1->next != NULL || s1->next->next != NULL || s1->next->next->next != NULL) {
        s2 = s1->next;
        s3 = s2->next;
        s1->next = NULL;
        Q->rear = s1;
        while (s3->next != NULL) {
            s2->next = s1;
            s1->last = s2;
            s1 = s2;
            s2 = s3;
            s3 = s2->next;
        }
    }
    s2->next = s1;
    s1->last = s2;
    s3->next = s2;
    s2->last = s3;
    Q->next = s3;
    s3->last = Q;
    Q->front = s3;
    //when last three nodes, do the following actions
    cout << "List flipped." << endl;
    s1 = s2 = s3 = nullptr;
    delete s1, s2, s3;
}

