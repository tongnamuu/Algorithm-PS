#include <iostream>
using namespace std;
#define MOD 1000000007
int a[100001];
long long solve(int x, int k) {
    long long val = 0;
    long long temp = 1;
    while (k) {
        if (k & 1) {
            val += temp;
            val %= MOD;
        }
        k >>= 1;
        temp *= x;
        temp %= MOD;
    }
    return val;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    long long ans = 0;
    for (int i = 0, x, k; i < n; ++i) {
        cin >> x >> k;
        ans += solve(x, k);
        ans %= MOD;
    }
    cout << ans;
}