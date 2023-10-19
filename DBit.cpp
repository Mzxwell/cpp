//
// Created by Jinx on 2023/10/18.
//
#include "iostream"
#include "bitset"

using namespace std;
union DAndI {
    double a = 0;
    unsigned long long u;
};

int main() {
    DAndI dAndI;
    cin >> dAndI.a;
    cout << bitset<64>(dAndI.u).to_string().substr(12)<<endl;
    int i = 1234567890;
    float f = 1.23456789e10;
    cout << (bool) (i == (int) (float) i) << (bool) (i == (int) (double) i) << (bool) (f == (float) (int) f)
         << (bool) (f == (float) (double) f);
}