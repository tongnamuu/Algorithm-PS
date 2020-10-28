#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 100000000
int a[101][101];
int from[101][101];
void find_path(int u, int v, vector<int>& path) {
    if (from[u][v] == -1) {
        path.push_back(u);
        if (u != v) path.push_back(v);
    }
    else {
        int k = from[u][v];
        find_path(u, k, path);
        path.pop_back();
        find_path(k, v, path);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = INF;
            from[i][j] = -1;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        a[u][v] = min(a[u][v], c);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    from[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == INF) cout << 0 << ' ';
            else cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i==j || a[i][j]==INF) cout << 0 << '\n';
            else {
                vector<int>path;
                find_path(i, j, path);
                cout << path.size() << ' ';
                for (int p : path) cout << p << ' ';
                cout << '\n';
            }
        }
    }
}
