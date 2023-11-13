#include "LinkStack.h"

int Random(int min, int max) {
    return (rand() % (max - min + 1)) + min;    //return a num in range [min,max]
}

StackNode *sn1;

int main() {
    InitStack(sn1);
    Push(sn1, Random(100, 999));
    Push(sn1, Random(100, 999));
    Push(sn1, Random(100, 999));
    Pop(sn1);
    Pop(sn1);
    Pop(sn1);
    Pop(sn1);
    DestroyStackNode(sn1);
}