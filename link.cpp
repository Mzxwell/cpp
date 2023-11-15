//
// Created by Jinx on 2023/10/22.
//
#include "solution.h"
using namespace std;

[[maybe_unused]] void swapS(node* cursor){
    cursor->right=cursor->right->right;
}
int main(){
    node* head=new node(0),*cursor=head;
    for (int i = 1; i <= 3; ++i) {
        cursor->right=new node(i);
        cursor=cursor->right;
    }
}