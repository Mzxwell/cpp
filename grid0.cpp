//
// Created by Jinx on 2024/2/28.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10;
int n;
int w[N][N];
int dp[N][N][N][N];

int main() {
    cin >> n;
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        w[a][b] = c;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++) {
                    if(i+j!=k+l)continue;
                    int &v = dp[i][j][k][l];
                    v = max(v, dp[i - 1][j][k - 1][l]);
                    v = max(v, dp[i - 1][j][k][l - 1]);
                    v = max(v, dp[i][j - 1][k - 1][l]);
                    v = max(v, dp[i][j - 1][k][l - 1]);
                    v += w[i][j];
                    if (i != k || j != l) v += w[k][l];
                }

    cout << dp[n][n][n][n] << endl;

    return 0;
}