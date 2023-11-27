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

void OutputPreOrderRecursion(Node *Root) {
    if (Root == NULL) return;
    cout << Root->data;
    OutputPreOrderRecursion(Root->left);
    OutputPreOrderRecursion(Root->right);
}

void OutputPreOrder(Node *Root) {
    Node *scanner = Root;
    struct StackNode *s;
    InitStack(s);

    while (1) {
        cout << scanner->data;
        if (scanner->left != NULL) {
            if (scanner->right != NULL) { //left != NULL, right != NULL
                Push(s, scanner->data);
                scanner = scanner->left;
            } else {    //left != NULL, right = NULL
                scanner = scanner->left;
            }
        } else {
            if (scanner->right != NULL) {   //left = NULL, right != NULL
                scanner = scanner->right;
            } else {    //left = NULL, right = NULL
                if (StackEmpty(s)) {    //finish
                    scanner = nullptr;
                    delete scanner;
                    DestroyStackNode(s);
                    return;
                }
                for (; scanner->data != GetTop(s); scanner = scanner->parent);
                scanner = scanner->right;
                Pop(s);
            }
        }
    }
}

void OutputInOrderRecursion(Node *Root) {
    if (Root == NULL) return;
    OutputInOrderRecursion(Root->left);
    cout << Root->data;
    OutputInOrderRecursion(Root->right);
}

void OutputInOrder(Node *Root) {
    Node *scanner = Root;
    struct StackNode *s;
    InitStack(s);

    while (1) {
        if (scanner->left != NULL) {
            Push(s, scanner->data);
            scanner = scanner->left;
        } else {
            if (scanner->right != NULL) {   //left = NULL, right != NULL
                cout << scanner->data;
                scanner = scanner->right;
            } else {    //left = NULL, right = NULL
                cout << scanner->data;
                if (StackEmpty(s)) {    //finish
                    scanner = nullptr;
                    delete scanner;
                    DestroyStackNode(s);
                    return;
                }
                while (1) {
                    for (; scanner->data != GetTop(s); scanner = scanner->parent);
                    if (scanner->right == NULL) {
                        cout << scanner->data;
                        Pop(s);
                    } else {
                        cout << scanner->data;
                        scanner = scanner->right;
                        Pop(s);
                        break;
                    }
                }
            }
        }
    }
}

void OutputPostOrderRecursion(Node *Root) {
    if (Root == NULL) return;
    OutputPostOrderRecursion(Root->right);
    OutputPostOrderRecursion(Root->left);
    cout << Root->data;
}

void OutputPostOrder(Node *Root) {  //special thanks to kbxx providing me inspiration
    //if tree empty
    if (Root->left == NULL && Root->right == NULL) {
        cout << Root->data;
        return;
    }
    Node *scanner = Root, *oneTap = nullptr;
    struct StackNode *s;
    InitStack(s);

    int rootPassed = 0;
    if (Root->left != NULL) rootPassed++;
    if (Root->right != NULL) rootPassed++;
    // start:
    while (1) {
        if (rootPassed == 0) {
            cout << Root->data;
            scanner = nullptr;
            delete scanner;
            DestroyStackNode(s);
            return;
        }
        //here, count how many times scanner passes Root
        //for binary tree with only left branch or right branch, the number would be 1
        //for binary tree with both left and right branch, the number would be 2
        //if pass times reached, the program should stop

        if (scanner->left != NULL) {
            if (scanner->right != NULL) { //left != NULL, right != NULL
                Push(s, scanner->data);
                scanner = scanner->right;
            } else {    //left != NULL, right = NULL
                Push(s, scanner->data);
                scanner = scanner->left;
            }
        } else {
            if (scanner->right != NULL) {   //left = NULL, right != NULL
                Push(s, scanner->data);
                scanner = scanner->right;
            } else {    //left = NULL, right = NULL
                cout << scanner->data;
                // b:
                while (1) {
                    for (; scanner->data != GetTop(s); scanner = scanner->parent);
                    if (scanner == oneTap) {
                        cout << scanner->data;
                        Pop(s);
                        // goto b;
                    }else if (scanner->left == NULL) {
                        cout << scanner->data;
                        Pop(s);
                    } else {
                        if (scanner->right != NULL) {   //left != null, right != null
                            oneTap = scanner;
                            if (oneTap == Root) rootPassed--;
                            scanner = scanner->left;
                            // goto start;
                            break;
                        } else {  //left != null, right = null
                            cout << scanner->data;
                            Pop(s);
                            // goto b;
                        }
                    }
                    // goto b;
                }
            }
        }
        // goto start;
    }
}

int InitStack(StackNode *&top) {
    top = new StackNode;
    if (top == NULL) {
        cout << "Initialization failed." << endl;
        return 0;
    }
    top->next = NULL;
    return 1;
}

int StackEmpty(StackNode *top) {
    return top->next == NULL ? 1 : 0;
}

void Push(StackNode *top, Datatype item) {
    if (StackEmpty(top) == 1) { //Adding first item to an empty stack
        top->next = new StackNode;
        top->next->data = item;
        top->next->next = NULL;
        return;
    }
    StackNode *connect = nullptr;
    connect = top->next;
    top->next = new StackNode;
    top->next->data = item;
    top->next->next = connect;
    connect = nullptr;
    delete connect;
}

void Pop(StackNode *top) {
    if (StackEmpty(top) == 1) {
        cout << "The stack is already empty!" << endl;
        return;
    }
    StackNode *output = nullptr;
    output = top->next;
    top->next = top->next->next;
    // cout << output->data;
    delete output;
    return;
}

char GetTop(StackNode *top) {
    return top->next->data;
}

void DestroyStackNode(StackNode *&top) {
    while (top->next != NULL) {
        StackNode *del = nullptr;
        del = top->next;
        top->next = top->next->next;
        delete del;
    }
    delete top;
}