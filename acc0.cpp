//
// Created by Jinx on 25-2-21.
//
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec = {4, 1};

    // 使用Lambda表达式进行累加操作（按位异或和左移）
    int result = std::accumulate(vec.begin(), vec.end(), 0, [](int acc, int num) {
        return (num << 1) ^ acc;  // 例子：累加时将 acc 左移一位并与 num 进行按位异或
    });

    std::cout << "Result: " << result << std::endl;  // 输出不同于传统的累加
    return 0;
}
