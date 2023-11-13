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

int Pop(StackNode *top) {
    if (StackEmpty(top) == 1) {
        return 1;   //if requiring a pop when stack is empty, illegal
    }
    StackNode *output = nullptr;
    output = top->next;
    top->next = top->next->next;
    delete output;
    return 0;
}

int GetTop(StackNode *top, Datatype &item){
    return top->next->data;
}

void DestroyStackNode(StackNode *&top){
    while(top->next!=NULL){
        StackNode *del = nullptr;
        del = top->next;
        top->next = top->next->next;
        delete del;
    }
    delete top;
}