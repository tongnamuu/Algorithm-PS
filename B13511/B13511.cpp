#include <iostream>
#include <vector>
using namespace std;
#define N 100001
vector<pair<int,int>>adj[N];
int depth[N];
long long dist[N];
int p[N][18];
int n;
int lca(int u, int v) {
    if (depth[u] < depth[v]) u ^= v ^= u ^= v;
    for (int i = 17; i >= 0; --i) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = p[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; --i) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
int kth(int u, int v, int k) {
    int x = lca(u, v);
    int l1 = depth[u] - depth[x];
    int l2 = depth[v] - depth[x];
    --k;
    if (k <= l1) {
        for (int i = 17; i >= 0; --i) {
            if (k & (1 << i)) {
                u = p[u][i];
            }
        }
        return u;
    }
    else {
        k = l1 + l2 - k;
        for (int i = 17; i >= 0; --i) {
            if (k & (1 << i)) {
                v = p[v][i];
            }
        }
        return v;
    }
}
void go(int now, int parent) {
    depth[now] = depth[parent] + 1;
    p[now][0] = parent;
    for (auto next : adj[now]) {
        if (next.first == parent) continue;
        dist[next.first] = dist[now] + next.second;
        go(next.first, now);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    go(1, 1);
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    int m; cin >> m;
    for (int i = 0, cmd, u, v, k; i < m; ++i) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> v;
            int x = lca(u, v);
            cout << dist[u] + dist[v] - 2 * dist[x] << '\n';
        }
        else {
            cin >> u >> v >> k;
            cout << kth(u, v, k) << '\n';
        }
    }
}