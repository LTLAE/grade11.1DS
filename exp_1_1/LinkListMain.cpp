#include "linklist.h"
#include <random>

using namespace std;

Node *List1;

int Random(int min, int max) {
    return (rand() % (max - min + 1)) + min;    //return a num in range [min,max]
}

int main() {
    InitList(List1);
    InsertItem(List1, 1, Random(100, 999));
    InsertItem(List1, 2, Random(100, 999));
    InsertItem(List1, 3, Random(100, 999));
    TraverseList(List1);

    int check;
    cout << "Input a number and check if it is in the list: ";
    cin >> check;
    cout << "The number is at " << FindItem(List1, check) << endl;

    int inputValue=0,inputPos=0;
    cout << "Input a number and its position you want to insert: ";
    cin >> inputValue >> inputPos;
    InsertItem(List1,inputPos,inputValue);
    TraverseList(List1);

    int del=0;
    cout << "Input a number you want to delete." << endl;
    cin >> del;
    DeleteItemViaData(List1,del);
    TraverseList(List1);

    FlipList(List1);
    TraverseList(List1);
    DestroyList(List1);
}