#include "LinkQueue.h"

int Random(int min, int max) {
    return (rand() % (max - min + 1)) + min;    //return a num in range [min,max]
}

QueueNode *qn1;

int main() {
    InitQueue(qn1);

    for (int timer = 0; timer < 10; timer++)
        EnQueue(qn1, Random(100, 999));

    TraverseQueue(qn1);

    FlipQueue(qn1);

    for (int timer = 0; timer < 10; timer++)
        DeQueue(qn1);
    DeQueue(qn1);

    Destroy(qn1);
}