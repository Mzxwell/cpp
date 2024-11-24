//
// Created by Jinx on 24-11-24.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode *> children;

    explicit TreeNode(int x) : val(x) {}
};

bool wangStrategy(int value, int parentValue, int p) {
    return value > p;
}

bool huStrategy(int value, int parentValue, int q, int k) { return value > q && value + parentValue > k; }

bool xieStrategy(int value, int parentValue, int q = 0, int k = 0) { return value % 2 == 0; }

void dfs(TreeNode *node, int parentValue, const function<bool(int, int)> &strategy, int &totalValue) {
    if (strategy(node->val, parentValue)) {
        totalValue = totalValue + node->val;
        for (auto child: node->children) dfs(child, node->val, strategy, totalValue);
    }
}

int main() {
    int n, p, q, k;
    cin >> n >> p >> q >> k;
    vector<TreeNode *> tree(n + 1);
    for (int i = 1; i <= n; ++i) tree[i] = new TreeNode(0);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x]->children.push_back(tree[y]);
    }
    vector<int> value(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
        tree[i]->val = value[i];
    }
    int wangTotal = 0;
    if (wangStrategy(tree[1]->val, 0, p)) {
        wangTotal = tree[1]->val;
        for (auto child: tree[1]->children)
            dfs(child, tree[1]->val, bind(wangStrategy, placeholders::_1, placeholders::_2, p), wangTotal);
    }
    int huTotal = 0;
    huTotal = tree[1]->val;
    for (auto child: tree[1]->children)
        dfs(child, tree[1]->val, bind(huStrategy, placeholders::_1, placeholders::_2, q, k), huTotal);
    int xieTotal = 0;
    if (xieStrategy(tree[1]->val, 0)) {
        xieTotal = tree[1]->val;
        for (auto child: tree[1]->children)
            dfs(child, tree[1]->val, bind(xieStrategy, placeholders::_1, placeholders::_2, q, k), xieTotal);
    }
    cout << wangTotal << " " << huTotal << " " << xieTotal << endl;
}