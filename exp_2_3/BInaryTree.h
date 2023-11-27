#include <iostream>
#include <string>
using namespace std;

typedef char DataType;
struct Node{
    DataType data;
    bool LThread = 0, RThread = 0;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
};

bool InitBT(Node *&Root);

void CreateBTviaString(Node *&Root,string);

void OutputInOrderRecursion(Node *Root);

void InOrderThread(Node *Root);

void InOrderThreadRun(Node *&Root);

void OutputInOrderWithThread(Node *Root);