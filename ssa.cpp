#include "iostream"

using namespace std;

int main() {
    int n, l = 0, r = 0, target, t = 0, re = 0, len;
    cin >> n;
    int nums[(len = n)];
    for (int i = 0; i < n; cin >> nums[i++]);
    cin >> target;
    while (r < n) {
        t += nums[r];
        if (t >= target) {
            while ((t -= nums[l]) >= target)l++;
            if (len > r - l)
                if (len = r - l, re = r + l, len == 0) {
                    re = l;
                    break;
                }
            l++;
        }
        r++;
    }
    cout << re;
}