//
// Created by Jinx on 24-10-21.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int m) {
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int solve(int mask, int currentPos, vector<pair<int, int>>& orders, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    if (mask == 0) return 0; // 全部订单完成，返回到1号点

    if (dp[mask][currentPos] != -1) return dp[mask][currentPos]; // 记忆化

    int res = INF;
    int n = orders.size();
    for (int i = 0; i < n; i++) {
        int pickUp = orders[i].first;
        int dropOff = orders[i].second;
        int pickUpMask = 1 << (i * 2);     // 商家的位
        int dropOffMask = 1 << (i * 2 + 1); // 顾客的位

        if (mask & pickUpMask) { // 还有餐没有取
            int newMask = mask ^ pickUpMask; // 更新mask，表示取了该餐
            res = min(res, dist[currentPos][pickUp] + solve(newMask, pickUp, orders, dist, dp));
        } else if (mask & dropOffMask) { // 餐已经取了，还没有送
            int newMask = mask ^ dropOffMask; // 更新mask，表示送了该餐
            res = min(res, dist[currentPos][dropOff] + solve(newMask, dropOff, orders, dist, dp));
        }
    }

    dp[mask][currentPos] = res; // 记忆化
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(m, vector<int>(m));

    // 读取距离矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) dist[i][j] = INF; // 无法到达的情况用 INF 表示
        }
    }

    floydWarshall(dist, m); // 预处理最短路径

    vector<pair<int, int>> orders(n); // 每个订单：{商家位置，顾客位置}
    for (int i = 0; i < n; i++) {
        cin >> orders[i].first >> orders[i].second;
        orders[i].first--;   // 下标从0开始
        orders[i].second--;
    }

    int totalStates = 1 << (2 * n); // 2 * n bits, 表示每个订单的取送状态
    vector<vector<int>> dp(totalStates, vector<int>(m, -1)); // 状态压缩DP数组

    int result = solve(totalStates - 1, 0, orders, dist, dp); // 从1号点出发，完成所有订单
    cout << result << endl;

    return 0;
}
