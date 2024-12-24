#include "iostream"

int main() {
    std::string s, s0;
    int k, i = 1, f = 0, l0 = 0, l, flag;
    std::cin >> s >> k;
    for (char c: s) if (c != '-') s0.push_back(toupper(c));
    for (flag = s0[0] < 'A' ? 1 : 2, l = s0.length(); i < l; flag |= s0[(i++) + l0] < 'A' ? 1 : 2)
        if (i % k == f) {
            if (s0.insert(i + (l0++), "-"), i / k == (k - 1) && i % k == 0) f = l % k, flag = 3;
            else if (flag -= 3) break;
        }
    std::cout << (flag == 3 ? s0 : "INVALID");
}