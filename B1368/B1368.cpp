#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int from, to, cap;
    bool operator<(const Edge& u) const {
        return cap < u.cap;
    }
};
int p[310];
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
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    vector<Edge> e;
    int n; cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        e.push_back({ 0, i, x });
        p[i] = i;
    }
    for (int i = 1, x; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if (i != j) {
                e.push_back({ i,j,x });
            }
        }
    }
    sort(e.begin(), e.end());
    int ans = 0;
    for (Edge& edge : e) {
        if (merge(edge.from, edge.to)) {
            ans += edge.cap;
        }
    }
    cout << ans;
}