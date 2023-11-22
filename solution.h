//
// Created by Administrator on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>
#include <algorithm>
#include <iostream>

#include "vector"

using namespace std;
struct node{
    int leftSide{};
    int num=0;
    node *right=nullptr,*left=nullptr;
};
static int setLeftSide(node *node0) {
    if(node0==nullptr)return 0;
    node0->leftSide=1+setLeftSide(node0->left);
    return node0->leftSide+setLeftSide(node0->right);
}
static int setNum(node*node0,int num) {
    if(node0==nullptr)return num-1;
    int left = setNum(node0->left,num);
    node0->num=left+1;
    int right = setNum(node0->right,left+2);
    return right;
}
static int k_thSmall(node const*node0,int offset,int k) {
    if(node0==nullptr)return 0;
    int rank=node0->leftSide+offset;
    if(rank==k)return node0->num;
    if(rank<k)return k_thSmall(node0->right,rank,k);
    return k_thSmall(node0->left,offset,k);
}
static void visit(node const*node0,bool isNum) {
    if (node0==nullptr)return;
    visit(node0->left,isNum);
    cout <<(isNum?node0->num:node0->leftSide)<<" ";
    visit(node0->right,isNum);
}
static int countLeaf(const node*node0) {
    if(node0==nullptr)return 0;
    node* l=node0->left,*r=node0->right;
    return l==nullptr&&r==nullptr? 1:countLeaf(l)+countLeaf(r);
}
static void swap(node*node0) {
    if(node0==nullptr)return;
    node *temp=node0->left,*r=node0->right;
    node0->left=r;
    node0->right=temp;
    swap(temp);
    swap(r);
}
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    [[maybe_unused]] ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution {
public:
    static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode  *now = new ListNode,*result=now;
        *now = ListNode();
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

class [[maybe_unused]] Solution {
public:
    vector<int> inorderTraversal(TreeNode const*root) {
        vector<int> a;
        if (root == nullptr)return a;
        a.push_back(root->val);
        if (root->right != nullptr || root->left != nullptr)traversal(root->left, a, root->right);
        return a;
    }

    void traversal(TreeNode const*left, vector<int> &a, TreeNode const*right) {
        if (left != nullptr) {
            vector<int> b = inorderTraversal(left);
            a.insert(a.begin(), b.begin(), b.end());
        }
        if (right != nullptr) {
            vector<int> b = inorderTraversal(right);
            a.insert(a.end(), b.begin(), b.end());
        }
           }
};

class Solution0 {
public:
    static TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *a = nullptr;
        if (nums.empty())return a;
        a = new TreeNode(nums[nums.size() / 2]);
        nums.erase(nums.begin() + (int)nums.size() / 2);
        vector<int> nums1;
        copy(nums.begin(), nums.begin() + ((int)nums.size() + 1) / 2, back_inserter(nums1));
        nums.erase(nums.begin(), nums.begin() + ((int)nums.size() + 1) / 2);
        a->left = sortedArrayToBST(nums1);
        a->right = sortedArrayToBST(nums);
        return a;
    }

    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        if (numRows == 0)return a;
        for (int i = 0; i < numRows; ++i) {
            vector<int> b;
            for (int j = 0; j <= i; ++j) {
                int c = (j && i ? a[i - 1][j - 1] : 0) + (j != i && i ? a[i - 1][j] : 0);
                b.push_back(c ? c : 1);
            }
            a.push_back(b);
        }
        return a;
    }

    static vector<vector<int>> permute(vector<int> nums) {
        vector<vector<int>> permutations;
        int trans;
        for (int a = 0; a < nums.size(); a++) {
            trans = nums[a];
            nums.erase(nums.begin() + a);
            vector<vector<int>> b = helper(trans, permute(nums));
            permutations.insert(permutations.end(), b.begin(), b.end());
            nums.insert(nums.begin() + a, trans);
        }
        return permutations;
    }

    static vector<vector<int>> helper(int a, vector<vector<int>> b) {
        for (auto &i: b)i.push_back(a);
        if (b.empty())b.push_back({a});
        return b;
    }

    int static ones(int num) { return num <= 1 ? num : ones(num / 2) + num % 2; }

    static int max(int arr[], int l, int r) {
        if (l == r)return arr[l];
        int mid = (l + r) / 2, a = max(arr, l, mid), b = max(arr, mid + 1, r);
        return a < b ? b : a;
    }

    static double average(int a[], int l, int r) {
        return l == r ? (double) a[r] / (r + 1) : (double) a[l] / (r + 1) + average(a, l + 1, r);
    }

    static auto nodeNum(ListNode const*a) -> int { return a == nullptr ? 0 : 1 + nodeNum(a->next); }

    static bool isPalindrome(string string1) {
        string1.erase(remove_if(string1.begin(), string1.end(), [](char i) { return isspace(i) || ispunct(i); }),
                      string1.end());
        transform(string1.begin(), string1.end(), string1.begin(), [](char c) { return tolower(c); });
        size_t len = string1.length();
        return string1.length() <= 1 || (string1[0] == string1[len - 1] && isPalindrome(string1.substr(1, len-2)));
    }
};

#endif //CPP_SOLUTION_H
