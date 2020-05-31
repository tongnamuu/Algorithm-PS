#include <iostream>
using namespace std;
long long d[2001][2001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    long long n, m, k; cin >> n >> m >> k;
    d[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j) d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % k;
            else d[i][j] = 1;
        }
    }
    long long ans = 1;
    while (n || m) {
        ans *= d[n%k][m%k];
        ans %= k;
        n /= k; m /= k;
    }
    cout << ans;
}