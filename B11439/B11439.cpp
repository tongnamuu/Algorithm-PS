#include <iostream>
using namespace std;
int check[4000001];
long long cnt(int x, long long fac) {
    long long ans = 0;
    long long temp = fac;
    while (temp <= x) {
        ans += x / temp;
        temp *= fac;
    }
    return ans;
}
long long _pow(long long a, long long r, int MOD) {
    long long ans = 1;
    while (r) {
        if (r & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        r >>= 1;
    }
    return ans;
}
long long solve(long long n, long long k, long long MOD) {
    long long ans = 1;
    for (long long i = 2; i <= n; ++i) {
        if (!check[i]) {
            ans *= _pow(i, cnt(n, i) - cnt(n - k, i) - cnt(k, i), MOD);
            ans %= MOD;
            for (long long j = i + i; j <= n; j += i) {
                check[j] = true;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    long long n, k, m; cin >> n >> k >> m;
    cout << solve(n, k, m);
}