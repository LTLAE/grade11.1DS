#include <iostream>

using namespace std;
typedef int DataType;
struct Node {
    DataType data;
    struct Node *next;
};

bool InitList(Node *&H);

bool IsListEmpty(Node *H);

void TraverseList(Node *H);

int FindItem(Node *H, DataType);

void InsertItem(Node *&H, int, DataType);

// void DeleteItemViaSeq(Node *&H, int);

void DeleteItemViaData(Node *&H, DataType);

void FlipList(Node *&H);

void DestroyList(Node *&H);