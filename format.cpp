//
// Created by Jinx on 24-9-20.
//
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    s.erase(remove(s.begin(), s.end(), '-'), s.end());
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    int flag = s[0] < 'A' ? 1 : 2;
    for (int i = 1, f = 0, l = s.length(),l0=0; i < l; i++) {
        if (i % k == f) {
            s.insert(i+l0, "-");
            l0++;
            if (i / k == (k-1) && i % k == 0) {
                f = l % k;
                flag = 3;
            } else {
                if (flag < 3) {
                    flag = 0;
                    break;
                }
                flag = 0;
            }
        }
        flag |= s[i+l0] < 'A' ? 1 : 2;
    }
    if (flag == 3)cout << s;
    else cout << "INVALID";
}