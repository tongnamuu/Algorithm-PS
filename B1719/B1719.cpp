#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int d[501][501];
int p[501][501];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) d[i][j] = INF;
        }
    }
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        d[v][u] = c;
        d[u][v] = c;
        p[v][u] = u;
        p[u][v] = v;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) cout << '-' << ' ';
            else cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
}