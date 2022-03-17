#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
int d[401][401];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) for(int j=1;j<=n;++j) d[i][j] = INF;
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        if (d[i][i] < INF) {
            ans = min(ans, d[i][i]);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans;
}
