#include <iostream>
using namespace std;
int a[101][101];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = -1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (!a[i][k]) continue;
            for (int j = 1; j <= n; ++j) {
                if (a[i][k] == a[k][j]) {
                    a[i][j] = a[i][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = 0, y = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 1) ++x;
            else if (a[i][j] == -1) ++y;
        }
        if (x > n / 2 || y > n / 2) ++ans;
    }
    cout << ans;
}
