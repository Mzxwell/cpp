#include <iostream>

using namespace std;

int main() {
    int a, n = 0, ans[200][200], dir[4][2] = {{0, 0},
                                              {0, 1},
                                              {1, 0},
                                              {1, 1}};
    char m2[200][200] = {0};
    string m[200];
    cin >> a;
    for (int i = 0; i < a; ++i) cin >> m[i];
    cout << "0" << endl;
    if (a == 1) return 0;
    for (int i = 0; i < a - 1; ++i)
        for (int j = 0; j < a - 1; ++j) {
            for (int k = 0; k < 4; k++)
                if (m[i + dir[k][0]][j + dir[k][1]] == '0')
                    m2[i][j]++;
            if ((ans[i][j] = (int) (unsigned char) m2[i][j]) == 2)n++;
        }
    cout << n << endl;
    if (a == 2)return 0;
    if (a == 3) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 4; i <= a; i += 2) {
        n = 0;
        cout << "0" << endl;
        for (int j = 0; j < a - i + 1; ++j)
            for (int k = 0; k < a - i + 1; ++k) {
                for (int l = 0; l < i; l += 2)
                    ans[j][k] += (int) (unsigned char) m2[j + i - 2][k + l] +
                                 (int) (unsigned char) m2[j + l][k + i - 2];
                ans[j][k] -= (int) (unsigned char) m2[j + i - 2][k + i - 2];
                if (ans[j][k] == i * i / 2)n++;
            }
        cout << n << endl;
    }
}
// 64 位输出请用 printf("%lld")