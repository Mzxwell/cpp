//
// Created by Jinx on 2023/11/15.
//
#include <iostream>
#include "solution.h"
using namespace std;
int main() {
    node *(node0[11]);
    for (int i=1;i<=10;i++)node0[i]=new node;
    node0[3]->left=node0[1];
    node0[3]->right=node0[2];
    node0[5]->left=node0[3];
    node0[5]->right=node0[4];
    node0[6]->left=node0[5];
    node0[6]->right=node0[7];
    node0[10]->left=node0[9];
    node0[10]->right=node0[6];
    node0[9]->left=node0[8];
    cout<< countLeaf(node0[10])<<endl;
    cout <<(node0[6]->left==node0[5]?"y ":"n ");
    swap(node0[10]);
    cout <<(node0[6]->left==node0[5]?"y ":"n ");
    cout<< countLeaf(node0[10])<<endl;
}