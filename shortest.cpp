//
// Created by Jinx on 24-9-21.
//
#include <algorithm>
#include "iostream"
#include "iterator"

using namespace std;

int main() {
    int n, target, start = 0, end = 0, sum = 0, r1, r2, f = 0, l;
    cin >> n;
    int nums[n];
    copy_n(istream_iterator<int>(cin), n, nums);
    cin >> target;
    while (end < n) {
        sum += nums[end];
        while (sum >= target) {
            if (!f || l > end-start) {
                l = end-start;
                r1 = start;
                r2 = end;
            }
            f = 1;
            if(start==end)break;
            sum -= nums[start++];
        }
        end++;
    }
    cout << (f ? r1 == r2 ? r1 : (r1 + r2) : 0);
}