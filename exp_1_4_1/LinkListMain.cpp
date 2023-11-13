#include "linklist.h"
#include <random>

using namespace std;

Node *List1;

int Random(int min, int max) {
    return (rand() % (max - min + 1)) + min;    //return a num in range [min,max]
}

int main() {
    InitList(List1);
    for(int timer=0;timer<10;timer++)   InsertItem(List1, 1, Random(100, 999));
    TraverseList(List1);

    int middle=0;
    cout << "Please input a middle number: ";
    cin >> middle;
    MoveNode(List1,middle);
    cout << "Start moving node according to demand..." << endl;
    TraverseList(List1);
}