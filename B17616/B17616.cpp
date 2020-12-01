#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100001
vector<int>adj[N];
vector<int>rev_adj[N];
int indegree[N];
int d[N];
int bfs(int cur, vector<int>* adj) {
    for (int i = 1; i < N; ++i) d[i] = -1;
    queue<int>q;
    q.push(cur);
    d[cur] = 0;
    int cnt = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        cnt += 1;
        for (int next : adj[now]) {
            if (d[next] == -1) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, x; cin >> n >> m >> x;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[v].push_back(u);
        rev_adj[u].push_back(v);
    }
    int front = bfs(x, adj) - 1;
    int back = bfs(x, rev_adj) - 1;
    int rest = n - front - back;
    cout << front + 1 << ' ' << front + rest;
}
