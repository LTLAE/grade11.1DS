#include "BInaryTree.h"

bool InitBT(Node *&Root) {
    Root = new Node;
    if (!Root) {
        cout << "Initialization fail." << endl;
        return 0;
    }
    Root->left = NULL;
    Root->right = NULL;
    return 1;
}

void CreateBTviaString(Node *&Root, string input) {
    Root->data = input[0];
    Node *scanner = Root;
    for (int timer = 1; timer < size(input); timer++) { //get 1 byte once
        if (input[timer] == '(') {
            scanner->left = new Node;
            scanner->left->parent = scanner;
            scanner->left->left = NULL;
            scanner->left->right = NULL;
            scanner = scanner->left;
        } else if (input[timer] == ',') {
            scanner = scanner->parent;
            if (input[timer - 1] == '(') { //if there is no left node, delete it
                Node *del;
                del = scanner->left;
                scanner->left = NULL;
                delete del;
            }
            scanner->right = new Node;
            scanner->right->parent = scanner;
            scanner->right->left = NULL;
            scanner->right->right = NULL;
            scanner = scanner->right;
        } else if (input[timer] == ')') {
            scanner = scanner->parent;
        } else {   //when data
            scanner->data = input[timer];
        }
    }
    scanner = nullptr;
    delete scanner;
}

void OutputInOrderRecursion(Node *Root) {
    if (Root == NULL) return;
    OutputInOrderRecursion(Root->left);
    cout << Root->data;
    OutputInOrderRecursion(Root->right);
}

Node *connect = nullptr;

void InOrderThread(Node *Root) {
    Node *newRoot = new Node;
    newRoot->RThread = 1;
    newRoot->right = Root;
    if (Root != NULL) {
        newRoot->left = Root;
        connect = newRoot;
        InOrderThreadRun(Root);
        connect->right = Root;
        connect->RThread = 1;
    } else {
        newRoot->left = newRoot;
    }
    cout << "Thread create complete." << endl;
    connect = nullptr;
    delete connect;
}

void InOrderThreadRun(Node *&Root) {
    if (Root == NULL) return;
    InOrderThreadRun(Root->left);
    if (Root->left == NULL) {
        Root->left = connect;
        Root->LThread = 1;
    }
    if (connect->right == NULL) {
        connect->right = Root;
        connect->RThread = 1;
    }
    connect = Root;
    InOrderThreadRun(Root->right);
}

void OutputInOrderWithThread(Node *Root) {
    Node *scanner = Root;
    int rootPassed = 0;
    //here according to calculation, scanner would pass root twice
    //the first time: all left nodes are outputted
    //the second time: output completed
    while (1) {
        for (; scanner->LThread != 1; scanner = scanner->left);   //put scanner to start node
        for (cout << scanner->data; scanner->RThread == 1 && scanner->right != Root; cout << scanner->data)
            scanner = scanner->right;
        scanner = scanner->right;
        if (scanner == Root) {  //all left nodes are outputted
            rootPassed++;
            cout << scanner->data;
            scanner = scanner->right;
        }
        if (rootPassed == 2) {  //output completed
            cout << '\b';   //here, my program would output root again at the end, so backspace it
            scanner = nullptr;
            delete scanner;
            return;
        }
    }
}