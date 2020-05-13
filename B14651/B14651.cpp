#include <iostream>
using namespace std;
#define MOD 1000000009
long long mpow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n; 
    if (n == 1) cout << 0;
    else cout << (2 * mpow(3, n - 2)) % MOD;
}