#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000
using Matrix = vector<vector<long long>>;
Matrix operator*(Matrix& a, Matrix& b){
    int n = a.size();
    Matrix c = vector<vector<long long>>(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}
Matrix MatPow(Matrix a, long long p) {
    int n = a.size();
    Matrix temp = vector<vector<long long>>(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) temp[i][i] = 1;
    while (p) {
        if (p & 1) {
            temp = a * temp;
        }
        a = a * a;
        p >>= 1;
    }
    return temp;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; long long b; cin >> n >> b;
    Matrix a = vector<vector<long long>>(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    Matrix ans = MatPow(a, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
