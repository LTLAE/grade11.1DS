#include "BInaryTree.h"

struct Node *bt1;

int main(){
    InitBT(bt1);
    CreateBTviaString(bt1,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    // CreateBTviaString(bt1,"A(B(D,E),C)");
    cout << "Without using thread:" << endl;
    OutputInOrderRecursion(bt1);
    cout << '\r' << "Using thread:" << endl;
    InOrderThread(bt1);
    OutputInOrderWithThread(bt1);
    cout << endl;
}