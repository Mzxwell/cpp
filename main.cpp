#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    int a[] = {0, 2, 1, -1};
    cout << Solution0::max(a, 0, 3) << endl << Solution0::average(a, 0, 3) << endl
         << Solution0::isPalindrome("Madam, I’m Adam");
    int x = 91;
    int y = 100, z = 0;
    while (y > 0) {
        if (x > 100) {
            x -= 10;
            y--;
        } else x++;
        z++;
    }
    int num, b = 0;
    cin >> num;
    for (int i = 1; i <= num; i++)for (int j = 1; j <= i; j++)for (int k = 1; k <= j; k++)b++;
    cout << b << endl << num * (num + 2) * (num + 1) / 6 << endl << z;
    return 0;
}
