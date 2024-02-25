//
// Created by Jinx on 2024/2/25.
//
#include "iostream"

using namespace std;

int main() {
    int n, x, y, k = -1;
    cin >> n;
    int **carpets = new int *[n];
    for (int i = 0; i < n; ++i) {
        carpets[i] = new int[4];
        for (int j = 0; j < 4; ++j) cin >> carpets[i][j];
    }
    cin >> x >> y;
    for (int i = n - 1; i >= 0; --i)
        if (x >= carpets[i][0] && x < carpets[i][2] + carpets[i][0] && y >= carpets[i][1] &&
            y < carpets[i][3] + carpets[i][1]) {
            k = i + 1;
            break;
        }
    cout<<k;
    for (int i = 0; i < n; ++i) delete[] carpets[i];
    delete[] carpets;
}