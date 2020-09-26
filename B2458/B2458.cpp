#include <iostream>
using namespace std;
int d[501][501];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        d[u][v] = 1;
        d[v][u] = -1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] == 1 && d[k][j] == 1) d[i][j] = 1;
                else if (d[i][k] == -1 && d[k][j] == -1) d[i][j] = -1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        bool s = true;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (!d[i][j]) {
                s = false;
                break;
            }
        }
        if (s) ++ans;
    }
    cout << ans;
}