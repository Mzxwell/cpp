//
// Created by Jinx on 2023/10/22.
//
#include "iostream"
using namespace std;
struct node{
    int num=0;
    node *right,*left;
};
void swapS(node* cursor){
    node*temp=cursor->right;
    cursor->right=cursor->right->right;
}
int main(){
    node* head=new node(0),*cursor=head;
    for (int i = 1; i <= 3; ++i) {
        cursor->right=new node(i);
        cursor=cursor->right;
    }
}