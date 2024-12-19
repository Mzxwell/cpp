#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool canSelectWithScore(const vector<int>& card, int n, int k, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (card[i] <= x) {
            ++count;
            i++;
        }
        if (count >= k) return true;
    }
    return false;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> card(n);
    for (int i = 0; i < n; ++i) cin >> card[i];
    int left = 1, right = *max_element(card.begin(), card.end());
    int result = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSelectWithScore(card, n, k, mid)) {
            result = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    cout << result << endl;
}