//
// Created by Jinx on 24-9-21.
//
#include <iomanip>
#include "iostream"
#include "cmath"

#define f(m) exp(m)-a*m-b
using namespace std;

int main() {
    double a, b, l = 0, r = 10, m = 5;
    cin >> a >> b;
    double res = f(m), lr = f(l), rr = f(r);
    while (res != 0) {
        if (rr * res < 0) l = m;
        else {
            r = m;
            rr = res;
        }
        m = (l + r) / 2;
        res = f(m);
    }
    cout << fixed << setprecision(6);
    cout<<m;
}