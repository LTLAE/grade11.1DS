#include <iostream>
#include <string>

using namespace std;

typedef char DataType;
struct Node {
    DataType data;
    int weight;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
};

bool InitBT(Node *&Root);

void CreateHuffmanBT(Node *&Root, string, int[]);

string Compress(Node *Root, string);

void FindChar(Node *Root,char);

string UnCompress(Node *Root,string);