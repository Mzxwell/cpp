//
// Created by Jinx on 2024/2/25.
//
#include <vector>
#include "iostream"

using namespace std;

struct p_node {
    int x,y;
    vector<p_node*> next;

    explicit p_node(int x,int y) : x(x),y(y), next() {}
};

static p_node pNode0 = p_node(0,0);
static int sum = 0, max_num = 0, board[9][9] = {0},N;

void second(p_node* pNode) {
    sum += board[pNode->x][pNode->y];
    if (pNode->next.empty()) {
        if (sum > max_num)max_num = sum;
    } else for (auto a: pNode->next)second(a);
    sum -= board[pNode->x][pNode->y];
}

void first(p_node* pNode) {
    int temp = board[pNode->x][pNode->y];
    board[pNode->x][pNode->y] = 0;
    sum += temp;
    if (pNode->next.empty()) second(&pNode0);
    else for (auto a: pNode->next) first(a);
    sum -= temp;
    board[pNode->x][pNode->y] = temp;
}

void creat(p_node* pNode, int x, int y) {
    int j0 = N;
    for (int i = x; i < N; ++i)
        for (int j = i == x ? y + 1 : y; j < j0; ++j)
            if (board[i][j]) {
                j0 = j;
                p_node* pNode1 = new p_node(i,j);
                creat(pNode1, i, j);
                pNode->next.push_back(pNode1);
            }
}

int main() {
    int x, y;
    cin>>N;
    while (1) {
        cin >> x >> y;
        if (!x)break;
        cin >> board[x-1][y-1];
    }
    creat(&pNode0, 0, 0);
    first(&pNode0);
    cout << max_num;
}