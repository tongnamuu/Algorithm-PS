#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>>adj[5001];
void dfs(int now, int p, const int k, int cur, int& ans) {
    if (cur >= k) ++ans;
    for (auto x : adj[now]) {
        if (x.first == p) continue;
        dfs(x.first, now, k, min(cur, x.second), ans);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1, u, v, r; i < n; ++i) {
        cin >> u >> v >> r;
        adj[u].push_back({ v,r });
        adj[v].push_back({ u,r });
    }
    for (int i = 0, u, k; i < q; ++i) {
        cin >> k >> u;
        int ans = -1;
        dfs(u, -1, k, 2000000000, ans);
        cout << ans << '\n';
    }
}
