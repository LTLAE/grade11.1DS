#include <iostream>
#include <algorithm>

using namespace std;

bool SequenceSearch(char input[], int size, char target);

bool BinarySearch(char input[], int size, char target);

typedef char DataType;
struct Node{
    DataType data;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
};

bool InitBT(Node *&Root);

void CreateBST(Node *&Root, char input[], int size);

void OutputBTviaString(Node *Root);

void OutputInOrderRecursion(Node *Root);