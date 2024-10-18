#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
struct Interval {
    int start;
    int end;
};

bool compare(Interval a, Interval b) {
    return a.end > b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++)cin >> intervals[i].start >> intervals[i].end;
    sort(intervals.begin(), intervals.end(), compare);
    stack<Interval> is;
    for (const auto &interval: intervals)is.push(interval);
    int current_position = 0, total_time = 0;
    while (!is.empty()) {
        while (current_position + 27 < is.top().start) {
            current_position += 27;
            total_time++;
        }
        if (is.top().end - current_position > 27)current_position += 27; else current_position = is.top().end;
        while (!is.empty()&&is.top().end >= current_position && is.top().start <= current_position)is.pop();
        total_time++;
    }
    cout << total_time << "T" << endl;
}