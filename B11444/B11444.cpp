#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007L
using Matrix = vector<vector<long long>>;
Matrix operator*(const Matrix& u, const Matrix& v) {
    int n = u.size();
    Matrix res(n, vector<long long>(n));
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = (u[i][k] * v[k][j] + res[i][j]) % MOD;
            }
        }
    }
    return res;
}
Matrix matrix_pow(Matrix a, long long b) {
    Matrix res(a.size(), vector<long long>(a.size()));
    for (int i = 0; i < res.size(); ++i) {
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    long long n; cin >> n;
    if (n <= 1) {
        cout << n;
        return 0;
    }
    Matrix x = {{1, 1}, {1, 0}};
    Matrix p = matrix_pow(x, n - 1);
    cout << p[0][0];
}
