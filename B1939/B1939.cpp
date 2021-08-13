#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>>adj[10001];
bool visit[10001];
bool connect(int n, queue<int>& q, long long x, int from, int to) {
    for (int i = 1; i <= n; ++i) visit[i] = 0;
    q.push(from); visit[from] = 1;
    while (!q.empty()) {                      
        int now = q.front(); q.pop();
        for (auto p : adj[now]) {
            if (!visit[p.first] && p.second >= x) {
                visit[p.first] = 1;
                q.push(p.first);
            }
        }
    }
    return visit[to];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        adj[v].push_back({ u,c });
    }
    int from, to; cin >> from >> to;
    long long s = 0, e = 1000000000;
    int ans = 0;
    queue<int>q;
    while (s <= e) {
        long long mid = s + e >> 1;
        if (connect(n, q, mid, from, to)) {
            ans = ans > mid ? ans : mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    cout << ans;
}
