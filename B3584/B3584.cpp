#include <iostream>
#include <vector>
using namespace std;
vector<int>adj[10001];
int p[10001][17];
int depth[10001];
void go(int now, int p) {
    depth[now] = depth[p] + 1;
    for (int next : adj[now]) {
        go(next, now);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) u ^= v ^= u ^= v;
    
    for (int i = 16; i >= 0; --i) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = p[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 16; i >= 0; --i) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) adj[i].clear(), p[i][0] = i, depth[i] = 0;
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            p[v][0] = u;
        }
        int root = -1;
        for (int i = 1; i <= n; ++i) {
            if (p[i][0] == i) root = i;
        }
        go(root, root);
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
        int x, y; cin >> x >> y; cout << lca(x, y) << '\n';
    }
}