#include <iostream>
using namespace std;
#define MOD 1000000003L
int d[1001][1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        d[i][1] = i;
        d[i][0] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            d[i][j] = (d[i - 2][j - 1] + d[i - 1][j]) % MOD;
        }
    }
    int ans = (d[n - 1][k] + d[n - 3][k - 1]) % MOD;
    cout << ans;
}
