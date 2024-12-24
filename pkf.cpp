#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string reformatLicenseKey(const string &s, int k) {
    // 去除破折号并转换为大写字母
    string cleaned;
    for (char c : s) {
        if (c != '-') {
            cleaned.push_back(toupper(c));
        }
    }

    // 计算总字符数，检查是否能够均匀分组
    int n = cleaned.size();
    int numGroups = (n + k - 1) / k; // 计算分组的总数
    vector<string> groups(numGroups);

    // 逐个填充组
    int index = 0;
    for (int i = 0; i < numGroups; ++i) {
        for (int j = 0; j < k && index < n; ++j) {
            groups[i].push_back(cleaned[index++]);
        }
    }

    // 检查每个组是否符合要求
    for (int i = 0; i < numGroups - 1; ++i) {
        bool isAlpha = true, isDigit = true;
        for (char c : groups[i]) {
            if (!isalpha(c)) isAlpha = false;
            if (!isdigit(c)) isDigit = false;
        }
        if (isAlpha || isDigit) {
            return "INVALID";
        }
    }

    // 合并各个组并返回格式化后的字符串
    string result;
    for (int i = 0; i < numGroups; ++i) {
        if (i > 0) result += "-";
        result += groups[i];
    }

    return result;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    string result = reformatLicenseKey(s, k);
    cout << result << endl;

    return 0;
}
