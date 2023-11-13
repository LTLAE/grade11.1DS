#include "LinkStack.h"

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

void Push(StackNode *&top, Datatype x, Datatype y) {
    if (StackEmpty(top) == 1) { //Adding first item to an empty stack
        top->next = new StackNode;
        top->next->x = x;
        top->next->y = y;
        top->next->next = NULL;
        return;
    }
    StackNode *connect = nullptr;
    connect = top->next;
    top->next = new StackNode;
    top->next->x = x;
    top->next->y = y;
    top->next->next = connect;
    connect = nullptr;
    delete connect;
}

void SlientPop(StackNode *top) {
    if (StackEmpty(top) == 1){
        cout << "Path notfound." << endl;
        abort();
    }
    StackNode *output = nullptr;
    output = top->next;
    top->next = top->next->next;
    delete output;
    return;
}

void Pop(StackNode *top) {
    if (StackEmpty(top) == 1) return;
    StackNode *output = nullptr;
    output = top->next;
    top->next = top->next->next;
    cout << "(" << output->x << " , " << output->y << ")" << endl;
    delete output;
    return;
}

void GetTop(StackNode *top) {
    cout << "(" << top->x << " , " << top->y << ")" << endl;
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

int GetTopX(StackNode *top) {
    return top->next->x;
}

int GetTopY(StackNode *top) {
    return top->next->y;
}