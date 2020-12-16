#include <iostream>
#include <algorithm>
using namespace std;
#define N 2001
struct Edge {
    int from, to, c;
    bool operator<(const Edge& a) const {
        return c < a.c;
    }
};
Edge edge[4 * N];
int edge_cnt;
int p[N];
struct UnionFind {
    UnionFind(int _n) {
        n = _n;
        init();
    }
    int n;
    void init() {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        p[u] = v;
        return true;
    }
};
long long MST(int n) {
    UnionFind u(n);
    long long ans = 0;
    sort(edge, edge + edge_cnt);
    for (int i = 0, total = 1; i < edge_cnt && total < n; ++i) {
        int from = edge[i].from;
        int to = edge[i].to;
        if (u.merge(from, to)) ans += edge[i].c;
    }
    return ans;
}
void solve() {
    int n, m; cin >> n >> m;
    edge_cnt = 0;
    for (int i = 1, u, c; i < n; ++i) {
        cin >> u  >> c;
        edge[edge_cnt].from = u;
        edge[edge_cnt].to = i;
        edge[edge_cnt++].c = c;
        edge[edge_cnt].to = u;
        edge[edge_cnt].from = i;
        edge[edge_cnt++].c = c;
    }
    long long ans = 0;
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        edge[edge_cnt].from = v;
        edge[edge_cnt].to = u;
        edge[edge_cnt++].c = c;
        edge[edge_cnt].to = v;
        edge[edge_cnt].from = u;
        edge[edge_cnt++].c = c;
        ans ^= MST(n);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
