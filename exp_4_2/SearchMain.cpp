#include <random>
#include "Search.h"

//random letter function from ChatGPT
char RandomLetter() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis('a', 'z');
    return static_cast<char>(dis(gen));
}

int main() {

    char array[16];
    for(int timer = 0; timer < sizeof(array); timer++) array[timer] = RandomLetter();
    cout << "The array is ";
    for(int timer = 0; timer < sizeof(array); timer++) cout << array[timer];
    cout << endl;

    char target;
    cout << "Please input the letter you want to search: ";
    cin >> target;
    cout << "Sequence search result: " << SequenceSearch(array,sizeof(array), target) << endl;
    cout << "Binary search result: " << BinarySearch(array, sizeof(array), target) << endl;

    char BSTArray[10];
    cout << "Please input 10 letter for BST: ";
    for (int timer = 0; timer < sizeof(BSTArray); timer++)  cin >> BSTArray[timer];
    Node *BST;
    InitBT(BST);
    CreateBST(BST,BSTArray,sizeof(BSTArray));
    cout << "BST In Order: ";
    OutputInOrderRecursion(BST);
    cout << '\r' << "BST string: ";
    OutputBTviaString(BST);
}