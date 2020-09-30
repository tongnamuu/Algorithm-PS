#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
#define N 5001
#define INF 1000000001
struct Edge {
    int v, c;
    bool operator<(const Edge& a) const {
        return c > a.c;
    }
};
vector<Edge>adj[N];
int d[N];
int g[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, p; cin >> n >> m >> p;
    if (p == 1 || p == n) {
        cout << "SAVE HIM";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
        g[i] = INF;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        adj[v].push_back({ u,c });
    }
    priority_queue<Edge>q;
    q.push({ 1,0 });
    d[0] = 0;
    while (!q.empty()) {
        int now = q.top().v;
        int c = q.top().c;
        q.pop();
        if (d[now] < c) continue;
        for (auto& e : adj[now]) {
            int next = e.v;
            int nc = e.c + c;
            if (d[next] > nc) {
                d[next] = nc;
                q.push({ next, nc });
            }
        }
    }
    q.push({ p,0 });
    g[p] = 0;
    while (!q.empty()) {
        int now = q.top().v;
        int c = q.top().c;
        q.pop();
        if (g[now] < c) continue;
        for (auto& e : adj[now]) {
            int next = e.v;
            int nc = e.c + c;
            if (g[next] > nc) {
                g[next] = nc;
                q.push({ next, nc });
            }
        }
    }
    if (d[n] == d[p] + g[n]) {
        cout << "SAVE HIM";
    }
    else {
        cout << "GOOD BYE";
    }
}