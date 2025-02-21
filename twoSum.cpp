//
// Created by Jinx on 25-2-20.
//
#include <unordered_map>
#include <string>
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int len = nums.size();
        vector<int> r(2);
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] == target) {
                    r[0] = i;
                    r[1] = j;
                    return r;
                }
            }
        }
        return r;
    }

    vector<int> twoSum0(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = map.find(target - nums[i]);
            if (it != map.end())return {it->second, i};
            map[nums[i]] = i;
        }
        return {};
    }

    bool isAnagram(int *a, int *b) {
        for (int i = 0; i < 130; ++i) if (a[i] != b[i])return false;
        return true;
    }

    int *sToN(string &a) {
        int *r = new int[130]{0};
        for (auto i: a)r[i]++;
        return r;
    };

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> r;
        vector<int *> ns;
        vector<string> ss;
        ss.push_back(strs[0]);
        r.push_back(ss);
        ns.push_back(sToN(strs[0]));
        for (int i = 1; i < strs.size(); ++i) {
            bool f = true;
            int *pInt = sToN(strs[i]);
            for (int j = 0; j < ns.size(); ++j) {
                if(strs[i].length()!=r[j][0].length())continue;
                if (isAnagram(ns[j], pInt)) {
                    r[j].push_back(strs[i]);
                    f = false;
                }
            }
            if (f) {
                r.push_back({strs[i]});
                ns.push_back(pInt);
            }
        }
        return r;
    }
};