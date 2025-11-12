//
// Created by Jinx on 25-2-20.
//
#include "queue"
#include <string>
#include <array>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include "vector"
#include "solution.h"
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> b(2);
        int a = 0, i0;
        for (i0 = 0; i0 < 32; ++i0) {
            if ((1 << i0) > n)break;
            if ((1 << i0) & n)b[a]++;
            a ^= 1;
        }
        return b;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        auto aHash = [fn = hash<int>()](array<int, 26> a) -> size_t {
            return accumulate(a.begin(), a.end(), 0u, [&](size_t acc, int num) -> size_t { return fn(num) + acc; });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(aHash)> mp(0, aHash);
        for (auto a: strs) {
            array<int, 26> count{};
            for (auto b: a)count[b - 'a']++;
            mp[count].push_back(a);
        }
        vector<vector<string>> r;
        for (auto a: mp)r.push_back(a.second);
        return r;
    }

    vector<vector<string>> groupAnagrams0(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (auto a: strs) {
            string string1 = a;
            sort(string1.begin(), string1.end());
            map[string1].emplace_back(a);
        }
        vector<vector<string>> r;
        for (auto a: map)
            r.emplace_back(a.second);
        return r;
    }

    int longestConsecutive(vector<int> &nums) {
        int max = 0;
        unordered_set<int> set;
        for (auto a: nums)set.insert(a);
        for (auto a: set) {
            if (!set.contains(a - 1)) {
                int t = 1;
                while (set.contains(++a))t++;
                if (t > max)max = t;
            }
        }
        return max;
    }

    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = nums.size(); i < j;) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.emplace_back(0);
                j--;
            } else {
                i++;
            }
        }
    }

    void moveZeroes0(vector<int> &nums) {
        for (int n = nums.size(), r = 0, l = 0; r < n; r++)
            if (nums[r])
                swap(nums[r], nums[l++]);
    }

    int maxArea(vector<int> &height) {
        int max0 = 0, l = 0, r = height.size() - 1, min0;
        while (r > l) min0 = height[l] < height[r] ? height[l++] : height[r--], max0 = max(max0, min0 * (r - l + 1));
        return max0;
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int i = 0, j = 1; nums[i] <= 0 && j < len; j = i + 1) {
            while (j < len && nums[i] + nums[j] * 2 <= 0) {
                int t = 0 - nums[i] - nums[j];
                if (set.contains(t) && (t != nums[j] || (j + 1 < len && t == nums[j + 1])))
                    ans.push_back({nums[i], nums[j], t});
                j++;
            }
            while ((++i) < len && nums[i] == nums[i - 1]);
        }
        return ans;
    }

    int trap0(vector<int> &height) {
#define h height
        int ans = 0, s = h.size();
        for (int l = 0, r = 1, t = 0; r < s; r++)if (h[r] >= h[l])l = r, ans += t, t = 0; else t += h[l] - h[r];
        for (int l = s - 2, r = s - 1, t = 0; l >= 0; l--)if (h[l] > h[r])r = l, ans += t, t = 0; else t += h[r] - h[l];
        return ans;
    }

    int trap(vector<int> &height) {
#define h height
        int a = 0, i = 0, j = 0, l = 0, r = height.size() - 1, b, c;
        while (l < r)if (b = h[l], i = max(i, b), c = h[r], j = max(j, c), i < j)a += i - b, l++; else a += j - c, r--;
        return a;
    }

    int lengthOfLongestSubstring0(string s) {
        int l = 0, r = 0, len = s.length(), ans = 0;
        unordered_map<char, int> map;
        while (r < len) {
            while (r < len && (map.find(s[r]) == map.end()))
                map[s[r++]] = r;
            ans = max(ans, r - l);
            if (r == len)
                break;
            for (int t = map[s[r]] + 1; l < t; ++l) map.erase(s[l]);
            l++;
        }
        return ans;
    }

    int lengthOfLongestSubstring(string s) {
        int r = 0, i = s.length(), m = 0;
        unordered_set<char> a;
        for (int l = 0; l < i; m = max(m, r - l), a.erase(s[l++]))while (r < i && !a.contains(s[r]))a.insert(s[r++]);
        return m;
    }

    int depth0(TreeNode *root) { return root == nullptr ? 0 : 1 + max(depth0(root->left), depth0(root->right)); }

    int maxDepth(TreeNode *root) {
#define P(t) if (t)Q.push(t)
        queue<TreeNode *> Q;
        P(root); else return 0;
        int ans = 0;
        for (; !Q.empty(); ans++)
            for (int i = Q.size(); i; --i, Q.pop()) {
                TreeNode *t = Q.front();
                P(t->right);
                P(t->left);
            }
        return ans;
    }


    int numIslands(vector<vector<char>> &g) {
        int ans = 0, x = g.size(), y = g[0].size(), t, r, fr, pr;
        vector<int> p(x * y, -1);
        function<int(int)> f = [&p, &f](int x) { return x == p[x] ? x : p[x] = f(p[x]); };
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j) {
                if (g[i][j] == '1') {
                    if (p[pr = i * y + j] == -1)p[pr] = pr, ans++;
                    if (p[pr] != -1) {
                        t = f(i * y + j);
                        if (i + 1 < x && g[i + 1][j] == '1')p[(i + 1) * y + j] = t;
                        if (j + 1 < y && g[i][j + 1] == '1') {
                            r = i * y + j + 1;
                            if (p[r] == -1)p[r] = t;
                            else if ((fr = f(r)) != t)p[t] = fr, ans--;
                        }
                    }
                }
            }
        return ans;
    }

};