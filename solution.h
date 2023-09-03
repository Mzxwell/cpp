//
// Created by Administrator on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *result, *now = new ListNode;
        *now = ListNode();
        result = now;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                now->next = list1;
                list1 = list1->next;
            } else {
                now->next = list2;
                list2 = list2->next;
            }
            now = now->next;
        }
        now->next = list2 == nullptr ? list1 : list2;
        return result->next;
    }

};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> a;
        if (root == nullptr)return a;
        a.push_back(root->val);
        if (root->right != nullptr || root->left != nullptr)traversal(root->left, a, root->right);
        return a;
    }

    void traversal(TreeNode *left, vector<int> &a, TreeNode *right) {
        if (left != nullptr) {
            vector<int> b = inorderTraversal(left);
            a.insert(a.begin(), b.begin(), b.end());
        }
        if (right != nullptr) {
            vector<int> b = inorderTraversal(right);
            a.insert(a.end(), b.begin(), b.end());
        }
        return;
    }
};

class Solution0 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *a = nullptr;
        if (nums.empty())return a;
        a = new TreeNode(nums[nums.size() / 2]);
        nums.erase(nums.begin() + nums.size() / 2);
        vector<int> nums1;
        copy(nums.begin(), nums.begin() + (nums.size() + 1) / 2, back_inserter(nums1));
        nums.erase(nums.begin(), nums.begin() + (nums.size() + 1) / 2);
        a->left = sortedArrayToBST(nums1);
        a->right = sortedArrayToBST(nums);
        return a;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        if(numRows==0)return a;
        for (int i = 0; i < numRows; ++i) {
            vector<int> b;
            for (int j = 0; j <=i; ++j) {
                int c=(j&&i?a[i-1][j-1]:0)+(j!=i&&i?a[i-1][j]:0);
                b.push_back(c?c:1);
            }
            a.push_back(b);
        }
        return a;
    }
};

#endif //CPP_SOLUTION_H
