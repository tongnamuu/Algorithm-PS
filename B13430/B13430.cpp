#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
using Mat = vector<vector<long long>>;
Mat operator*(const Mat& a, const Mat& b){
    int n = a.size();
    Mat c = Mat(n, vector<long long>(n));
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
Mat matpow(const Mat& u, long long n) {
    int k = u.size();
    Mat temp = u;
    Mat ans = Mat(k, vector<long long>(k));
    for (int i = 0; i < k; ++i) {
        ans[i][i] = 1;
    }
    while (n) {
        if (n & 1) ans = ans * temp;
        temp = temp * temp;
        n >>= 1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int k, n; cin >> k >> n;
    k += 2;
    Mat d = Mat(k, vector<long long>(k));
    for (int i = 0; i < k; ++i) {
        for (int j = i; j < k; ++j) {
            d[i][j] = 1;
        }
    }
    d = matpow(d, n - 1);
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += d[0][i];
        ans %= MOD;
    }
    cout << ans;
}