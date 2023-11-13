#include <iostream>

using namespace std;

typedef int Datatype;
struct StackNode {
    Datatype x;
    Datatype y;
    struct StackNode *next;
};

int InitStack(StackNode *&top);

int StackEmpty(StackNode *top);

void Push(StackNode *&top, Datatype, Datatype);

void SlientPop(StackNode *top);

void Pop(StackNode *top);

void GetTop(StackNode *top);

void DestroyStackNode(StackNode *&top);

int GetTopX(StackNode *top);

int GetTopY(StackNode *top);