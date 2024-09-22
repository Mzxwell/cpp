//
// Created by Jinx on 24-9-22.
//
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

// 将月份名称转换为数字
int getMonthNumber(const string& month) {
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; ++i) {
        if (month == months[i]) {
            return i + 1;
        }
    }
    return 0; // 如果输入的月份不合法
}

int main() {
    int year, day, hour, minute, second;
    string month;

    // 输入电子表当前的时间
    cin >> year >> month >> day >> hour >> minute >> second;

    // 电子表参考时间：2024-09-01T22:20:00
    tm ref_time = {};
    ref_time.tm_year = 2024 - 1900;
    ref_time.tm_mon = 9 - 1;
    ref_time.tm_mday = 1;
    ref_time.tm_hour = 22;
    ref_time.tm_min = 20;
    ref_time.tm_sec = 0;

    // 将输入的时间转换为tm结构体
    tm input_time = {};
    input_time.tm_year = year - 1900;
    input_time.tm_mon = getMonthNumber(month) - 1;
    input_time.tm_mday = day;
    input_time.tm_hour = hour;
    input_time.tm_min = minute;
    input_time.tm_sec = second;

    // 计算两者的时间差（秒）
    time_t ref_epoch = mktime(&ref_time);
    time_t input_epoch = mktime(&input_time);
    double time_diff = difftime(input_epoch, ref_epoch); // 计算秒数差

    // 因为每小时滞后1分钟，所以需要进行调整
    double real_seconds_passed = time_diff / 59.0 * 60.0;

    // 计算真实的北京时间
    time_t real_time_epoch = ref_epoch + static_cast<time_t>(real_seconds_passed);
    tm* real_time = gmtime(&real_time_epoch);

    // 输出结果，格式化为ISO 8601标准
    cout << put_time(real_time, "%Y-%m-%dT%H:%M:%S") << endl;

    return 0;
}
