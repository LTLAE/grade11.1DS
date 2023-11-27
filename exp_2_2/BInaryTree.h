#include <iostream>
#include <string>
using namespace std;

typedef char DataType;
struct Node{
    DataType data;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
};

bool InitBT(Node *&Root);

void CreateBTviaString(Node *&Root,string);

void OutputPreOrderRecursion(Node *Root);

void OutputPreOrder(Node *Root);

void OutputInOrderRecursion(Node *Root);

void OutputInOrder(Node *Root);

void OutputPostOrderRecursion(Node *Root);

void OutputPostOrder(Node *Root);

typedef char Datatype;
struct StackNode {
    Datatype data;
    struct StackNode *next;
};

int InitStack(StackNode *&top);

int StackEmpty(StackNode *top);

void Push(StackNode *top, Datatype item);

void Pop(StackNode *top);

char GetTop(StackNode *top);

void DestroyStackNode(StackNode *&top);