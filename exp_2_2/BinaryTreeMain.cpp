#include "BInaryTree.h"

struct Node *bt1;

int main(){
    InitBT(bt1);
    CreateBTviaString(bt1,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    // CreateBTviaString(bt1,"A(B(D,E),C)");
    OutputPreOrderRecursion(bt1);
    cout << endl;
    OutputPreOrder(bt1);
    cout << endl;
    OutputInOrderRecursion(bt1);
    cout << endl;
    OutputInOrder(bt1);
    cout << endl;
    OutputPostOrderRecursion(bt1);
    cout << endl;
    OutputPostOrder(bt1);
}