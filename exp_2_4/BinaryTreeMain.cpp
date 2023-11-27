#include "BInaryTree.h"

struct Node *bt1;

int main() {
    string chars = "!IPSUWkzjCy.vw,Tfgmbpudlcorhnstaie ";   //use * as space
    int charsWeight[35] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7, 8, 9, 10, 13, 14, 17, 18, 19, 21, 23,
                           31, 31, 33, 37, 37, 55, 77};
    InitBT(bt1);
    CreateHuffmanBT(bt1, chars, charsWeight);
    string original = "The Chinese official said he viewed the Trump Presidency not as an aberration but as the product of a failing political system. This jibes with other accounts. The Chinese leadership believes that the United States, and Western democracies in general, haven’t risen to the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure.";
    string compressed = Compress(bt1,original);
    cout << "Compress result:" << endl;
    cout << compressed << endl; //for debugging
    cout << "Uncompress result:" << endl;
    cout << UnCompress(bt1,compressed) << endl;

}