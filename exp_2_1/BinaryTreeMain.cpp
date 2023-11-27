#include "BInaryTree.h"

struct Node *bt1;

int main(){
    InitBT(bt1);
    CreateBTviaString(bt1,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    // CreateBTviaString(bt1,"A(B(D,E)C)");
    OutputBTviaString(bt1);
    cout << endl;
    OutputSpecificChildren(bt1,'H');
    cout << "There are(is) " << HowManyNodes(bt1) << " node(s) in the tree." << endl;
    cout << "There are(is) " << HowManyLeaves(bt1) << " leave(s) in the tree." << endl;
    cout << "The tree has " << HowManyDegrees(bt1) << " degree(s)." << endl;
    cout << "Depth of the tree is " << FindDepth(bt1) << endl;
}