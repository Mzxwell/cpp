//
// Created by Jinx on 25-2-20.
//
#include <string>
#include <array>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include "vector"

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
        for (int i=0,j=nums.size();i<j;) {
            if (nums[i] == 0){
                nums.erase(nums.begin()+i);
                nums.emplace_back(0);
                j--;
            }else{
                i++;
            }
        }
    }
    void moveZeroes0(vector<int> &nums) {for (int n = nums.size(), r = 0, l = 0; r < n; r++)if (nums[r])swap(nums[r], nums[l++]);}
};

}