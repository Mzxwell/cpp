//
// Created by Jinx on 2024/2/24.
//
#include <iostream>

using namespace std;

int main() {
    int B1, B2, C1, C2;
    cin >> B1 >> B2 >> C1 >> C2;
    long long board[21][21] = {0};
    for (int i = 0; i <= B1; ++i) {
        for (int j = 0; j <= B2; ++j) {
            if (abs((i - C1) * (j - C2)) == 2||(i==C1&&j==C2))continue;
            if (!i && !j)board[i][j] = 1;
            else if (!j)board[i][j] = board[i - 1][j];
            else if (!i)board[i][j] = board[i][j - 1];
            else board[i][j] = board[i - 1][j] + board[i][j - 1];
        }
    }
    cout << board[B1][B2];
}