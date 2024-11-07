#include <vector>
#include "algorithm"
#include "iostream"
#include "string"

using namespace std;

int main() {
    vector<string> floors;
    string command, floor = "";
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "add") {
            cin >> floor;
            floors.push_back(floor.substr(2));
        } else if (command == "del") {
            cin >> floor;
            auto item = find(floors.begin(), floors.end(), floor.substr(2));
            floors.erase(item);
        } else {
            if (cin.peek() == ' ') {

            } else {
                size_t max_length = 0;  // 存储最大长度
                for (const auto &str: floors) if (str.size() > max_length) max_length = str.size();  // 更新最大长度
                for(int j = 0;j<floors.size();j++){
                    int l=0;
                    cout<<"0x";
                    while (max_length>)
                }
            }
        }
    }
}