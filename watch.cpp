//
// Created by Jinx on 24-9-21.
//
#include "iostream"
#include "iomanip"

#define ull unsigned long long
using namespace std;
ull md[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
ull mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string months[] = {"",
                   "January",
                   "February",
                   "March",
                   "April",
                   "May",
                   "June",
                   "July",
                   "August",
                   "September",
                   "October",
                   "November",
                   "December"};

ull y2d(int y) {
    if (y == 2024)return 0;
    ull y0 = y - 2024, y1 = y0 * 365 + y0 / 4 + (y0 % 4 == 0 ? 0 : 1), y2 = y - 2100, y3 = y - 2400, y4 =
            y1 - (y2 / 100 + (y2 % 100 == 0 ? 0 : 1));
    if (y < 2100)return y1;
    if (y < 2400)return y4;
    return y4 + (y3 / 400 + (y3 % 400 == 0 ? 0 : 1));
}

ull m2d(int m, int y) {
    return md[m] + (m > 2 && (y % 4 == 0 && (y % 100 || y % 400 == 0)) ? 1 : 0);
}

int one_m2d(int m, int y) {
    return m == 2 && (y % 4 == 0 && (y % 100 || y % 400 == 0)) ? 29 : mon[m];
}

unsigned long long to_sec(int year, int m, int day, int hour, int minute, int second) {
    return (((y2d(year) + m2d(m, year) + day - 1) * 24 + hour) * 60 + minute) * 60 - 57 + second;
}

int main() {
    int year, m, day, hour, minute, second;
    string month;
    cin >> year >> month >> day >> hour >> minute >> second;
    for (int i = 0; i < 13; ++i) if (months[i] == month)m = i;
    if (year == 2024 && m == 1 && day == 1 && hour == 0 && minute == 0 && second < 57) {
        second = 2 + second;
        cout << ("2024-01-10T22:02:") << setw(2) << setfill('0') << second;
        return 0;
    }
    ull re = to_sec(year, m, day, hour, minute, second);
    second = re % 59;
    re = re / 59;
    minute = 3 + (re % 60);
    hour = 22;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    re = re / 60;
    hour += re % 24;
    day = 10;
    if (hour >= 24) {
        hour -= 24;
        day++;
    }
    day += re / 24;
    m = 1;
    year = 2024;
    int t = one_m2d(m, year);
    while (day > t) {
        day -= t;
        m++;
        if (m > 12) {
            m = 1;
            year++;
        }
        t = one_m2d(m, year);
    }
    cout << year << "-" << setw(2) << setfill('0') << m << "-" << setw(2) << setfill('0') << day << "T" << setw(2)
         << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0')
         << second;
    return 0;
}