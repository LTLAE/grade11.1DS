#include "linklist.h"

using namespace std;

bool InitList(Node *&H) {
    H = new Node;
    if (!H) {
        cout << "Initialization fail." << endl;
        return 0;
    }
    H->next = NULL;
    return 1;
}

bool IsListEmpty(Node *H) {
    return H->next == NULL ? 1 : 0;
}

void TraverseList(Node *H) {
    Node *scanner = nullptr;
    scanner = H->next;
    cout << "Start outputting data." << endl;
    while (scanner->next != NULL) {
        cout << scanner->data << endl;
        scanner = scanner->next;
    }
    cout << scanner->data << endl;    //last node
    scanner = nullptr;
    delete scanner;
    cout << "All data was shown." << endl;
}

int FindItem(Node *H, DataType input) {
    Node *scanner = nullptr;
    int pos = 1;
    for (scanner = H->next; scanner->data != input; pos++) {
        if (scanner->next == NULL) {  //Last node
            delete scanner;
            return -1;
        }
        // cout << scanner -> data << endl; //debug
        scanner = scanner->next;
    }
    scanner = nullptr;
    delete scanner;
    return pos;
}

void InsertItem(Node *&H, int pos, DataType input) {
    if (pos < 1) {  //pos must greater then 1
        cout << "Your position is invalid." << endl;
        return;
    }
    Node *scanner = nullptr, *connect = nullptr;
    for (scanner = H; scanner->next != NULL; pos--) {
        if (pos == 1) { //insert new between [scanner -> next] and [scanner -> next -> next]
            connect = scanner->next;  //structure: scanner -> new -> connect
            scanner->next = new Node;
            scanner->next->data = input;
            scanner->next->next = connect;
            scanner = connect = nullptr;
            delete scanner;
            cout << "Insert successful." << endl;
            return;
        }
        scanner = scanner->next;
    }
    if (pos == 1) {  //last node
        scanner->next = new Node;
        scanner->next->next = NULL;
        scanner->next->data = input;
        scanner = connect = nullptr;
        delete scanner, connect;
        cout << "Insert successful." << endl;
        return;
    } else {  //not found
        cout << "Your position exceeded the length of linklist." << endl;
        scanner = connect = nullptr;
        delete scanner, connect;
        return;
    }


}

/*
void DeleteItemViaSeq(Node *&H, int pos) {
    if (pos < 1) {  //pos must greater then 1
        cout << "Your position is invalid." << endl;
        return;
    }
    Node *scanner = nullptr, *del = nullptr;
    for (scanner = H; scanner->next != NULL; pos--) {
        if (pos == 1) {
            del = scanner->next;
            if (scanner->next->next == NULL) {  //last node
                scanner->next = NULL;
            } else {    //not last node
                scanner->next = scanner->next->next;
            }
            delete del;
            return;

        }
        scanner = scanner->next;
    }
    cout << "Your position exceeded the length of linklist." << endl;
    return;
}
*/

void DeleteItemViaData(Node *&H, DataType input) {
    Node *scanner = nullptr, *del = nullptr;
    for (scanner = H; scanner->next != NULL; scanner = scanner->next) {
        if (scanner->next->data == input) {
            del = scanner->next;
            if (scanner->next->next == NULL) {  //last node
                scanner->next = NULL;
            } else {    //not last node
                scanner->next = scanner->next->next;
            }
            scanner = nullptr;
            delete scanner, del;
            return;
        }
    }
    cout << "Item not found." << endl;
    delete scanner;
    return;
}

void FlipList(Node *&H) {
    //when 4+ nodes,three pointers point to three connected nodes then do the following actions
    //s1 -> n1, s2 -> n2, s3 -> n3
    //n2 -> n1, s1 -> n4, then repeat
    //check whether the number of nodes is less than 3
    Node *s1 = H->next, *s2 = nullptr, *s3 = H->next;
    //Check if last three nodes.
    if (s1->next != NULL || s1->next->next != NULL || s1->next->next->next != NULL) {
        s2 = s1->next;
        s3 = s2->next;
        s1->next = NULL;
        while (s3->next != NULL) {
            s2->next = s1;
            s1 = s2;
            s2 = s3;
            s3 = s2->next;
        }
    }
    s2->next = s1;
    s3->next = s2;
    H->next = s3;
    //when last three nodes, do the following actions
    cout << "List flipped." << endl;
    s1 = s2 = s3 = nullptr;
    delete s1, s2, s3;
}

void DestroyList(Node *&H) {
    Node *scanner = nullptr, *del = nullptr;
    for (scanner = H; scanner->next != NULL; delete del) {
        del = scanner;
        scanner = scanner->next;
    }
    delete scanner; //last node;
}

void MoveNode(Node *&H, DataType input) {
    if (IsListEmpty(H) == 1) {  //check if list is empty
        cout << "The list is empty!" << endl;
        return;
    }
    if (H->next->next == NULL) {    //check if list only has one node
        return;
    }
    //condition above do not need sort
    Node *scanner = H, *move = nullptr, *rear = nullptr;    //rear always at rear of the list
    int Length = 0;
    for (scanner = H->next; scanner->next != NULL; scanner = scanner->next) Length++;    //move *rear to rear
    // special thank to danjuaner's echo giving me idea
    rear = scanner;
    scanner = H;
    for (int timer = 0; timer < Length; timer++) {
        move = scanner->next;
        if (move->data < input) {   //insert to H->next
            scanner = scanner->next;
        } else if (move->data > input) {    //insert to rear->next
            scanner->next = scanner->next->next;
            move->next = NULL;
            rear->next = move;
            rear = rear->next;
        }
    }
    scanner = move = rear = nullptr;
    delete scanner, move, rear;
    cout << "Node moved according to demand." << endl;
}

