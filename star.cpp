//
// Created by Jinx on 24-10-19.
//
#include <cstdio>
#include <cstring>

int n, m, matrix[2000][2000], dx[4] = {1, -1, 0, 0},
dy[4] = {0, 0, 1, -1};
bool visited[2000][2000]={0};

void dfs(int x, int y, int color) {
    visited[x][y] = true;
    matrix[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]
        && matrix[nx][ny] == color) dfs(nx, ny, color);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        scanf("%d", &matrix[i][j]);
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    //memset(visited, false, sizeof(visited));
    dfs(x, y, matrix[x][y]);
    for (int j = 0; j < m; j++) {
        int writeIndex = n - 1;
        for (int i = n - 1; i >= 0; i--) if (matrix[i][j] != 0)
            matrix[writeIndex--][j] = matrix[i][j];
        for (int i = writeIndex; i >= 0; i--) matrix[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}