#include <iostream>
#include <algorithm>
using namespace std;
#define N 200001
struct Edge {
    int to, from, c;
    bool operator<(const Edge& a) const {
        return c < a.c;
    }
};
Edge edge[N];

int p[N];
struct UnionFind {
    UnionFind(int n) {
        init(n);
    }
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    UnionFind u(0);
    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            cin >> edge[i].from >> edge[i].to >> edge[i].c;
            ans += edge[i].c;
        }
        sort(edge, edge + m);
        u.init(n);
        for (int i = 0; i < m; ++i) {
            if (u.merge(edge[i].to, edge[i].from)) {
                ans -= edge[i].c;
            }
        }
        cout << ans << '\n';
    }
}