#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <stack>

using namespace std;

int main() {
    int MEMORY_SIZE = 1000, dataPointer = 0;
    string cmd, output;
    getline(cin, cmd);
    vector<uint8_t> memory(MEMORY_SIZE, 0);
    vector<int> jump(cmd.length(), 0);
    stack<int> loopStack;
    for (int i = 0; i < cmd.length(); i++)
        if (cmd[i] == '[') loopStack.push(i);
        else if (cmd[i] == ']') {
            int start = loopStack.top();
            loopStack.pop();
            jump[start] = i;
            jump[i] = start;
        }
    char c;
    uint8_t byte;
    if (std::cin.get(c))byte = c; else byte = 0;
    for (int i = 0; i < cmd.length(); i++) {
        switch (cmd[i]) {
            case '>':
                dataPointer++;
                break;
            case '<':
                dataPointer--;
                break;
            case '+':
                memory[dataPointer]++;
                break;
            case '-':
                memory[dataPointer]--;
                break;
            case '.':
                output += static_cast<char>(memory[dataPointer]);
                break;
            case ',':
                memory[dataPointer] = byte;
                if (std::cin.get(c)) byte = c; else byte = 0;
                break;
            case '[':
                if (memory[dataPointer] == 0) i = jump[i];
                break;
            case ']':
                if (memory[dataPointer] != 0) i = jump[i];
                break;
            default:
                break;
        }
    }
    cout << output;
}