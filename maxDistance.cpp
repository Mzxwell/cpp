//
// Created by Jinx on 25-2-19.
//
#include "algorithm"
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        int max1, max2, min1, min2, i1 = 0, i2 = 0;
        vector<int> maxE, minE;
        for (auto a: arrays) {
            maxE.push_back(*max_element(a.begin(), a.end()));
            minE.push_back(*min_element(a.begin(), a.end()));
        }
        max1 = maxE[0];
        min1 = minE[0];
        for (int i = 0; i < maxE.size(); ++i) {
            if (maxE[i] > max1) {
                max1 = maxE[i];
                i1 = i;
            }
        }
        for (int i = 0; i < maxE.size(); ++i) {
            if (minE[i] < min1) {
                min1 = minE[i];
                i2 = i;
            }
        }
        if(i1!=i2)return max1-min1;
        maxE.erase(maxE.begin()+i1);
        minE.erase(minE.begin()+i2);
        max2=*max_element(maxE.begin(),maxE.end());
        min2=*min_element(minE.begin(), minE.end());
        if(max1-max2>min2-min1)return max1-min2;
        return max2-min1;
    }
};