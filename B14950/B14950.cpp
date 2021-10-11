#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 10001
vector<pair<int, int>>adj[N];
int d[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, t; cin >> n >> m >> t;
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        adj[v].push_back({ u,c });
    }
    priority_queue<pair<int, int>>q;
    q.push({ 0, 1 });
    int ans = 0;
    while (!q.empty()) {
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();
        if (d[now]) continue;
        d[now] = 1;
        ans += cost;
        for (auto next : adj[now]) {
            q.push({ - next.second, next.first });
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        ans += i * t;
    }
    cout << ans;
}
