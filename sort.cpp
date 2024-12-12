#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

bool compareNumeric(string &a, string &b) {
    int numA = stoi(a);
    int numB = stoi(b);
    return numA < numB;
}

bool compareIgnoreCase(string &a, string &b) {
    string lowerA = a;
    string lowerB = b;
    transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
    transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
    return lowerA < lowerB;
}

bool compareAlphaNumeric(string &a, string &b) {
    string cleanedA, cleanedB;
    for (char c: a) if (isalnum(c) || c == ' ') cleanedA += c;
    for (char c: b) if (isalnum(c) || c == ' ') cleanedB += c;
    return cleanedA < cleanedB;
}

int main() {
    size_t N;
    cin >> N;
    cin.ignore();
    vector<string> strings(N);
    for (size_t i = 0; i < N; ++i)getline(cin, strings[i]);
    size_t C;
    cin >> C;
    cin.ignore();
    for (size_t i = 0; i < C; ++i) {
        string command;
        getline(cin, command);
        function<bool(string &, string &)> compareFunc = [](string &a, string &b) { return a < b; };
        bool isNumeric = false, ignoreCase = false, alphaNumericOnly = false, reverse = false;
        for (char c: command) {
            if (c == '-') continue;
            switch (c) {
                case 'n':
                    isNumeric = true;
                    break;
                case 'i':
                    ignoreCase = true;
                    break;
                case 'd':
                    alphaNumericOnly = true;
                    break;
                case 'r':
                    reverse = true;
                    break;
                default:
                    break;
            }
        }
        if (isNumeric) compareFunc = compareNumeric;
        else if (ignoreCase) compareFunc = compareIgnoreCase;
        else if (alphaNumericOnly) compareFunc = compareAlphaNumeric;
        if (reverse)
            sort(strings.begin(), strings.end(), [&compareFunc](string &a, string &b) { return !compareFunc(a, b); });
        else sort(strings.begin(), strings.end(), compareFunc);
        for (const auto &str: strings) cout << str << endl;
    }
}
