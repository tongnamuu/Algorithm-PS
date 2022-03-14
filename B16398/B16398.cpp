#include <iostream>
#include <algorithm>
using namespace std;
#define N 1001
int p[1001];
struct UnionFind {
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
struct Edge {
    int from, to;
    long long c;
};
Edge e[2000002];
int cnt;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0, x; i < n; ++i) {
        p[i] = i;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            e[cnt++] = Edge({ i, j, x });
        }
    }
    sort(e, e + cnt, [](Edge& u, Edge& v) {
        return u.c < v.c;
    });
    UnionFind uf;
    long long ans = 0;
    for (int i = 0; i < cnt; ++i) {
        int from = e[i].from;
        int to = e[i].to;
        if (uf.merge(from, to)) {
            ans += e[i].c;
        }
    }
    cout << ans;
}