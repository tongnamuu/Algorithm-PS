#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int to, c;
};
vector<Edge>adj[10001];
int dfs(int now, int parent, int cur, int& ans, int& point) {
    int res = 0;
    for (auto next : adj[now]) {
        if (next.to == parent) continue;
        int d = dfs(next.to, now, cur + next.c, ans, point);
        res = max(res, d);
    }
    if (!res) {
        if (ans < cur) {
            ans = cur;
            point = now;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        adj[v].push_back({ u,c });
    }
    int s = 1;
    int d = 0;
    dfs(1, 1, 0, d, s);
    dfs(s, s, 0, d, s);
    cout << d << '\n';
}
