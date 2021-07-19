#include<iostream>
#include<string>
using namespace std;
long long d[100002][16];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tc; int T; cin >> T;
    const long long MOD = 1000000007;
    for (tc = 1; tc <= T; ++tc) {
        string s; cin >> s;
        int n = s.length();
        for (register int i = 1; i <= 15; ++i) {
            d[1][i] = 0;
            if (i & 1) if (i&(1 << (s[0] - 'A'))) d[1][i] = 1;
        }
        for (register int i = 2; i <= n; ++i) {
            for (register int j = 1; j <= 15; ++j) {
                d[i][j] = 0;
                if (j&(1 << (s[i - 1] - 'A'))) {
                    for (register int k = 1; k <= 15; ++k) {
                        if (j&k) {
                            d[i][j] = (d[i][j] + d[i - 1][k]) % MOD;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (register int i = 1; i <= 15; ++i) ans = (ans + d[n][i]) % MOD;
        cout << '#' << tc << ' ' << ans << '\n';
    }
}
