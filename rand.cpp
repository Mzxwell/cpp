//
// Created by Jinx on 2024/2/28.
//
#include <random>
#include "iostream"

using namespace std;
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);
    cout<<9<<endl;
    for (int i = 1; i < 10; ++i) for (int j = 1; j < 10; ++j)cout<<i<<" "<<j<<" "<<dis(gen)<<endl;
    cout<<"0 0 0";
}