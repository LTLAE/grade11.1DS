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

void OutputBTviaString(Node *Root);

void OutputSpecificChildren(Node *Root,DataType);

int HowManyNodes(Node *Root);

int HowManyNodesCount(Node *Root);

int HowManyLeaves(Node *Root);

int HowManyLeavesCount(Node *Root);

int HowManyDegrees(Node *Root);

int HowManyDegreesCount(Node *Root);

int FindDepth(Node *Root);