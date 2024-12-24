//
// Created by Jinx on 24-12-24.
//
#include "iostream"

#define IV {cout << "INVALID";return 0;}
using namespace std;

bool vps(string s) {
    char f = 0;
    for (auto a: s)f |= ((!(f & 0b001)) && a >= '0' && a <= '9') ? 0b001 : 0b010;
    return f != 0b011;
}

int main() {
    size_t k, pos, len, len0, j = 0;
    string s;
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')s[i] ^= 0x20;
        if (s[i] == '-')s.erase(i--, 1);
    }
    if (len = s.size(), len0 = len % k, pos = k * (k - 1), (len < pos) && len0 != 0) IV
    if (len0 == 0)len0 = k;
    string ss[len / k + 1];
    for (int i = 0; i < len; j++)
        if (i == pos) ss[j] = s.substr(i, len0), i += len0;
        else {
            ss[j] = s.substr(i, k);
            if (vps(ss[j])) IV
            i += k;
        }
    for (int i = 0; i < j; i++)cout << (i == j - 1 ? ss[i] : (ss[i] + "-"));
}