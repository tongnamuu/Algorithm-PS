#include <iostream>
using namespace std;
#define MOD 1000000007
long long _pow(long long a, long long r) {
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
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
        ans %= MOD;
    }
    long long val = 1;
    for (int i = 1; i <= k; ++i) {
        val *= i;
        val %= MOD;
    }
    for (int i = 1; i <= n - k; ++i) {
        val *= i;
        val %= MOD;
    }
    ans *= _pow(val, MOD - 2);
    ans %= MOD;
    cout << ans;
}