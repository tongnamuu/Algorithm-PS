#include<iostream>
using namespace std;
int d[16][16];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    d[0][1] = 1;
    int  x = -1, y = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] = d[i - 1][j] + d[i][j - 1];
            k--;
            if (k == 0) x = i, y = j;
        }
    }
    if (x == -1) cout << d[n][m];
    else cout << d[x][y] * d[n - x + 1][m - y + 1];
}
