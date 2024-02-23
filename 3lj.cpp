//
// Created by Jinx on 2024/2/23.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "set"
using namespace std;
set<int> byt(int a){
    set<int>mySet={a%10,(a/10)%10,a/100};
    return mySet;
}
int main(){
    for (int i = 123; i < 330; ++i) {
        set<int> set1;
        for (int j = 1; j <= 3; ++j) {
            set<int> a=byt(j*i);
            set1.insert(a.begin(),a.end());
        }
        if(set1.size()==9&&set1.find(0)==set1.end())cout<< i<<" "<<i*2<<" "<<i*3<<endl;
    }
}