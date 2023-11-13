#include <iostream>

using namespace std;

typedef int Datatype;
struct StackNode {
    Datatype data;
    struct StackNode *next;
};

int InitStack(StackNode *&top);

int StackEmpty(StackNode *top);

void Push(StackNode *top, Datatype item);

void Pop(StackNode *top);

int GetTop(StackNode *top, Datatype &item);

void DestroyStackNode(StackNode *&top);