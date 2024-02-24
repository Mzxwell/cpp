//
// Created by Jinx on 2024/2/24.
//
#include <set>
#include <vector>
#include "iostream"
#define pa pair<int,int>
using namespace std;
bool isPoint(pa A,vector<pa> point){
    for(auto p:point)if(A==p)return true;
    return false;
}
int road(pa A,pa B,vector<pa> C){
    if(A==B)return 1;
    if(A.first>B.first||A.second>B.second|| isPoint(A,C))return 0;
    return road(pair(A.first+1,A.second),B,C)+road(pair(A.first,A.second+1),B,C);
}
int main(){
    int B1,B2,C1,C2;
    cin>>B1>>B2>>C1>>C2;
    vector<pa> point={pair(C1,C2),pair(C1-2,C2-1),pair(C1-2,C2+1),pair(C1-1,C2-2),pair(C1-1,C2+2),pair(C1+1,C2-2),pair(C1+1,C2+2),pair(C1+2,C2-1),pair(C1+2,C2+1)};
    cout<< road(pair(0,0),pair(B1,B2),point);
}