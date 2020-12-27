#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
    int from, to, c;
};
Edge edge[200001];
bool man[1001];
int p[1001];
struct UnionFind {
    int n;
    UnionFind(int _n) { n = _n; for (int i = 1; i <= n; ++i) p[i] = i; }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        char c; cin >> c;
        if (c == 'M') man[i] = 1;

    }
    int pn = 0;
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        if (man[u] ^ man[v]) {
            edge[pn++] = { u,v,c };
            edge[pn++] = { v,u,c };
        }
    }
    sort(edge, edge + pn, [](const Edge& u, const Edge& v) {
        return u.c < v.c;
    });
    int sz = 1;
    int ans = 0;
    UnionFind uf(n);
    for (int i = 0; i < pn; ++i) {
        int from = edge[i].from;
        int to = edge[i].to;
        if (uf.merge(from, to)) {
            ans += edge[i].c;
            sz += 1;
        }
    }
    if (sz != n) cout << -1;
    else cout << ans;
}
