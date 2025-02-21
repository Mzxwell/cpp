//
// Created by Jinx on 25-2-20.
//
#include <string>
#include <array>
#include <numeric>
#include <unordered_map>
#include <algorithm>
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
        for (auto a : strs) {
            string string1 = a;
            sort(string1.begin(), string1.end());
            map[string1].emplace_back(a);
        }
        vector<vector<string>> r;
        for (auto a : map)
            r.emplace_back(a.second);
        return r;
    }
};