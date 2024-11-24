//
// Created by Jinx on 24-11-24.
//
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<long long>> Matrix;
const long long MOD = 1e9 + 7;

Matrix multiply(const Matrix &A, const Matrix &B, int n) {
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix identityMatrix(int n) {
    Matrix I(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) I[i][i] = 1;
    return I;
}

Matrix fastPower(Matrix A, long long p, int n) {
    Matrix result = identityMatrix(n);
    while (p > 0) {
        if (p & 1) result = multiply(result, A, n);
        A = multiply(A, A, n);
        p >>= 1;
    }
    return result;
}

int main() {
    int n;
    long long p;
    cin >> n >> p;
    Matrix A(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> A[i][j];
    Matrix result = fastPower(A, p, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << result[i][j] << " ";
        cout << endl;
    }
}