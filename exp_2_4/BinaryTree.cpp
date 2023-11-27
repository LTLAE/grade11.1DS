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

void CreateHuffmanBT(Node *&Root, string chars, int charsWeight[]) {
    Node *buildL = nullptr;
    buildL = new Node;
    buildL->left = NULL;
    buildL->right = NULL;
    buildL->data = chars[0];
    buildL->weight = charsWeight[0];
    if (size(chars) == 1) {  //if only 1 character
        Root = buildL;
        buildL = nullptr;
        delete buildL;
        return;
    }
    Node *buildR = nullptr;

    for (int timer = 1; timer <= size(chars); timer++) {
        if (buildL->weight < charsWeight[timer + 1]) {  //left tree, right node
            buildR = nullptr;
            buildR = new Node;
            buildR->left = NULL;
            buildR->right = NULL;
            buildR->data = chars[timer];
            buildR->weight = charsWeight[timer];
        } else if (buildL->weight >= charsWeight[timer + 1]) {  //left tree, right tree
            buildR = nullptr;
            buildR = new Node;
            buildR->left = NULL;
            buildR->right = NULL;
            buildR->data = chars[timer];
            buildR->weight = charsWeight[timer];
            buildR->parent = new Node;
            buildR->parent->right = buildR;
            timer++;
            buildR->parent->left = new Node;
            buildR->parent->left->parent = buildR->parent;
            buildR->parent->left->data = chars[timer];
            buildR->parent->left->weight = charsWeight[timer];
            buildR->parent->weight = buildR->weight + buildR->parent->left->weight;
            buildR = buildR->parent;
        }

        //create subtree
        buildR->parent = new Node;
        buildL->parent = buildR->parent;
        buildR->parent->left = buildL;
        buildR->parent->right = buildR;
        buildR->parent->weight = buildL->weight + buildR->weight;
        Root = buildR->parent;
        buildL = buildL->parent;

    }
    Root = Root->left;
}

Node *scanner = nullptr;

string Compress(Node *Root, string original) {
    string compressed;
    Node *pos = nullptr;    //make pos = original[timer]
    for (int timer = 0; timer <= size(original); timer++) { //find code for each letter
        string compressedLetter = "";
        FindChar(Root, original[timer]);
        while (1) {
            if (scanner->parent->left == scanner) compressedLetter.insert(0, "0");
            else if (scanner->parent->right == scanner) compressedLetter.insert(0, "1");
            if (scanner == Root) break;
            scanner = scanner->parent;
        }
        compressedLetter.erase(0,1);
        compressed += compressedLetter + ",";
    }
    return compressed;
}

void FindChar(Node *Root, char input) {
    if (Root->data == input) {
        scanner = Root;
        return;
    }
    if (Root->left != NULL) FindChar(Root->left, input);
    if (Root->right != NULL) FindChar(Root->right, input);
}

string UnCompress(Node *Root, string input) {
    string output;
    int timer = 0;
    while (timer < size(input)-1) {
        scanner = Root;
        for (; input[timer] != ','; timer++) {    //read
            if (input[timer] == '0') scanner = scanner->left;
            else if (input[timer] == '1') scanner = scanner->right;
        }
        output += scanner->data;
        timer++;
    }
    return output;
}