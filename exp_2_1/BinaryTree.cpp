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

void OutputSpecificChildren(Node *Root, DataType input) {
    if (Root->data == input) {
        cout << "Children of " << input << " are " << "Left: " << Root->left->data << " Right: " << Root->right->data
             << endl;
    }
    if (Root->left == NULL) {
        if (Root->right == NULL) {                                 //left = null, right = null
            return;
        } else {
            OutputSpecificChildren(Root->right, 'H');   //left = null, right != null
        }
    } else if (Root->right == NULL) {                              //left != null, right = null
        OutputSpecificChildren(Root->left, 'H');
    } else {                                                       //left != null, right != null
        OutputSpecificChildren(Root->left, 'H');
        OutputSpecificChildren(Root->right, 'H');
    }

}

int num = 0;    //the number of nodes
int HowManyNodes(Node *Root) {
    num = 0;    //reset counter
    return HowManyNodesCount(Root);
}

int HowManyNodesCount(Node *Root) {
    if (Root->left == NULL) {
        if (Root->right == NULL) {    //left = null, right = null
            num++;
        } else {                      //left = null, right != null
            num++;
            HowManyNodesCount(Root->right);
        }
    } else {
        if (Root->right == NULL) {    //left != null, right = null
            num++;
            HowManyNodesCount(Root->left);
        } else {                      //left != null, right != null
            num++;
            HowManyNodesCount(Root->left);
            HowManyNodesCount(Root->right);
        }
    }
    return num;
}

int HowManyLeaves(Node *Root) {
    num = 0;
    return HowManyLeavesCount(Root);
}

int HowManyLeavesCount(Node *Root) {
    if (Root->left == NULL) {
        if (Root->right == NULL) {    //left = null, right = null
            num++;
        } else {                      //left = null, right != null
            HowManyLeavesCount(Root->right);
        }
    } else {
        if (Root->right == NULL) {    //left != null, right = null
            HowManyLeavesCount(Root->left);
        } else {                      //left != null, right != null
            HowManyLeavesCount(Root->left);
            HowManyLeavesCount(Root->right);
        }
    }
    return num;
}

int HowManyDegrees(Node *Root) {
    num = 0;
    return HowManyDegreesCount(Root);
}

int HowManyDegreesCount(Node *Root) {
    if (Root->left == NULL) {
        if (Root->right != NULL) {    //left = null, right != null
            num++;
            HowManyDegreesCount(Root->right);
        }
    } else {
        if (Root->right == NULL) {    //left != null, right = null
            num++;
            HowManyDegreesCount(Root->left);
        } else {                      //left != null, right != null
            num += 2;
            HowManyDegreesCount(Root->left);
            HowManyDegreesCount(Root->right);
        }
    }
    return num;
}


int FindDepth(Node *Root) {
    if (Root->left == NULL) {
        if (Root->right != NULL) {    //left = null, right != null
            int rightDepth = FindDepth(Root->right);
            return rightDepth + 1;
        }
    } else {
        if (Root->right == NULL) {    //left != null, right = null
            int leftDepth = FindDepth(Root->left);
            return leftDepth + 1;
        } else {                      //left != null, right != null
            int leftDepth = FindDepth(Root->left);
            int rightDepth = FindDepth(Root->right);
            return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
        }
    }   //left = null, right = null
    return 1;
}