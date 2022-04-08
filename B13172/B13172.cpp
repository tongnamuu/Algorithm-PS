#include <iostream>
using namespace std;
#define MOD 1000000007L
long long inverse(long long u) {
    long long val = 1;
    long long x = u;
    long long r = MOD - 2;
    while (r) {
        if (r & 1) {
            val = (val * x) % MOD;
        }
        x = x * x % MOD;
        r >>= 1;
    }
    return val;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long u, v; cin >> u >> v;
        ans += (v * inverse(u)) % MOD;
        ans %= MOD;
    }
    cout << ans;
}