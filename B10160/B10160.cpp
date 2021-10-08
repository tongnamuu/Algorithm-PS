#include <iostream>
using namespace std;
#define MOD 1000000009L
long long d[1000005][7];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    d[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        d[i][0] = (d[i - 1][0] * (k - 1) + d[i - 1][1] * (k - 2) + d[i - 1][2] * (k - 2) + d[i - 1][3] * (k - 2) + +d[i - 1][4] * (k - 2) + d[i - 1][5] * (k - 2) + d[i - 1][6] * (k - 2)) % MOD;
        d[i][1] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][3] + d[i - 1][5] + d[i - 1][6]) % MOD;
        d[i][2] = d[i - 1][1];
        d[i][3] = (d[i - 1][2] + d[i - 1][4]) % MOD;
        d[i][4] = d[i - 1][3];
        d[i][5] = d[i - 1][2];
        d[i][6] = d[i - 1][5];
    }
    long long ans = (d[n][0] + d[n][1] + d[n][2] + d[n][3] + d[n][4] + d[n][5] + d[n][6]) % MOD;
    cout << ans;
}
