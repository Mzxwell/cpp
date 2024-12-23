#include "iostream"
#include "algorithm"
#include "vector"

#define SI(a) stoi(a.substr(0,2))*60+stoi(a.substr(3,2))
using namespace std;

int main() {
    int n, k;
    string s0, s1;
    cin >> n;
    vector<pair<int, int>> ts(k = n);
    while (n--) {
        cin >> s0;
        s1 = s0.substr(6, 5);
        s0 = s0.substr(0, 5);
        ts[n] = {SI(s0), SI(s1)};
    }
    sort(ts.begin(), ts.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });
    for (auto a: ts)if (a.first >= n)k--, n = a.second;
    cout << k;
}