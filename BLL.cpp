//
// Created by Jinx on 2023/11/15.
//
#include "solution.h"
using namespace std;

int main() {
    node* (node0[11]);
    for (int i = 1; i <= 10; i++)node0[i] = new node;
    node0[3]->left = node0[1];
    node0[3]->right = node0[2];
    node0[5]->left = node0[3];
    node0[5]->right = node0[4];
    node0[6]->left = node0[5];
    node0[6]->right = node0[7];
    node0[10]->left = node0[9];
    node0[10]->right = node0[6];
    node0[9]->left = node0[8];
    cout << countLeaf(node0[10]) << endl;
    cout << (node0[6]->left == node0[5] ? "y " : "n ");
    cout << (node0[6]->left == node0[5] ? "y " : "n ");
    cout << countLeaf(node0[10]) << endl;
    cout << setLeftSide(node0[10]) << endl;
    visit(node0[10],false);
    cout << endl;
    setNum(node0[10], 1);
    visit(node0[10],true);
    cout << endl<< k_thSmall(node0[10],0,2)<<endl<<isBST(node0[10]);
    node0[5]->num=0;
    cout<< isBST(node0[10])<<endl;
    visit(node0[10],true);
    cout<<endl;
    vector<int> a={1,8,51,65,2,55,48,98,21,33,24,44,6,70,99,50,20,111,23,147};
    a=Solution0::heapsort(a,20,80);
    for (const auto b:a)cout<<b<<" ";
}