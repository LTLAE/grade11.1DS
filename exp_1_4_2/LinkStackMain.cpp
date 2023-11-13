#include "LinkStack.h"
#include <string>

int Random(int min, int max) {
    return (rand() % (max - min + 1)) + min;    //return a num in range [min,max]
}

StackNode *sn1;

bool IsNestLegal(string input) {
    for (int timer = 0; timer < size(input); timer++) {
        if (input[timer] == '(') Push(sn1, 1);
        else if (input[timer] == ')') {
            if (Pop(sn1) == 1) return 0;    //illegal
        }
    }
    return StackEmpty(sn1) == 1;    //if empty, legal; if not, illegal
}

int main() {
    InitStack(sn1);
    string str;
    cout << "Please input a string includes ( and ): ";
    cin >> str;
    cout << IsNestLegal(str) << endl;

}