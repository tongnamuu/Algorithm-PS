#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int from, to, c;
};
int p[1001];
struct UnionFind {
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        p[x] = y;
        return 1;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    vector<Edge> e;
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i <= n; ++i) p[i] = i;
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        e.push_back({ 0, x, 0 });
        e.push_back({ x, 0, 0 });
    }
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        e.push_back({ u, v, c });
        e.push_back({ v, u, c });
    }
    sort(e.begin(), e.end(), [](const Edge& u, const Edge& v) {
        return u.c < v.c;
    });
    UnionFind uf;
    int ans = 0;
    for (Edge& edge : e) {
        if (uf.merge(edge.from, edge.to)) {
            ans += edge.c;
        }
    }
    cout << ans;
}