#include "Search.h"

bool SequenceSearch(char input[], int size, char target) {
    for (int timer = 0; timer < size; timer++) {
        if (target == input[timer]) {
            cout << "Find target in " << timer + 1 << " compares." << '\t';
            return true;
        }
    }
    cout << "Target not found." << '\t';
    return false;
}

bool BinarySearch(char input[], int size, char target) {
    char sortedInput[size], front = 0, rear = size - 1, middle = (front + rear) / 2;
    int compareCount = 0;\
    //copy array
    for (int timer = 0; timer < size; timer++) sortedInput[timer] = input[timer];
    //use built in quick sort
    sort(&sortedInput[0],&sortedInput[size]);
    compareCount++;
    while (sortedInput[middle] != target) {
        if (front == rear) {
            cout << "Target not found." << '\t';
            return false;
        }
        if (target < sortedInput[middle]) {
            compareCount++;
            rear = middle;
            middle = (front + rear) / 2;
        }
        if (target > sortedInput[middle]) {
            compareCount++;
            front = middle + 1;
            middle = (front + rear) / 2;
        }
    }
    cout << "Find target in " << compareCount << " compares." << '\t';
    return true;
}

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

void CreateBST(Node *&Root, char input[], int size) {
    Root->data = input[0];
    Node *scanner;
    for (int timer = 1; timer < size; timer++) {
        scanner = Root;
        while (true) {
            if (input[timer] < scanner->data) {
                if (scanner->left == NULL) {
                    scanner->left = new Node;
                    scanner->left->data = input[timer];
                    scanner->left->parent = scanner;
                    break;
                } else {
                    scanner = scanner->left;
                }
            } else {
                if (scanner->right == NULL) {
                    scanner->right = new Node;
                    scanner->right->data = input[timer];
                    scanner->right->parent = scanner;
                    break;
                } else {
                    scanner = scanner->right;
                }
            }
        }
    }
    scanner = nullptr;
    delete scanner;
}

void OutputBTviaString(Node *Root) {
    if (Root->left == NULL) {
        if (Root->right == NULL) {    //left = null, right = null
            cout << Root->data;
        } else {                      //left = null, right != null
            cout << Root->data;
            cout << "(,";
            OutputBTviaString(Root->right);
            cout << ")";
        }
    } else {
        if (Root->right == NULL) {    //left != null, right = null
            cout << Root->data;
            cout << "(";
            OutputBTviaString(Root->left);
            cout << ")";
        } else {                      //left != null, right != null
            cout << Root->data;
            cout << "(";
            OutputBTviaString(Root->left);
            cout << ",";
            OutputBTviaString(Root->right);
            cout << ")";
        }
    }
}

void OutputInOrderRecursion(Node *Root) {
    if (Root == NULL) return;
    OutputInOrderRecursion(Root->left);
    cout << Root->data;
    OutputInOrderRecursion(Root->right);
}