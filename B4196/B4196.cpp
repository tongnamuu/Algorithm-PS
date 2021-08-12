#include <iostream>
#include <vector>
#include <list>
using namespace std;
#define N 100001
vector<int>adj[N];
vector<int>rev[N];
int indegree[N];
int visit[N];
void dfs1(int now, list<int>& result) {
    visit[now] = 1;
    for (int next : adj[now]) {
        if (!visit[next]) {
            dfs1(next, result);
        }
    }
    result.push_front(now);
}
void dfs2(int now) {
    visit[now] = 2;
    for (int next : adj[now]) {
        if (visit[next] == 1) {
            dfs2(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear(); visit[i] = 0; rev[i].clear();
        }
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
        list<int>result;
        for (int i = 1; i <= n; ++i) {
            if (!visit[i]) dfs1(i, result);
        }

        int ans = 0;
        for (int i : result) {
            if (visit[i] == 1) {
                dfs2(i); ++ans;
            }
        }
        cout << ans << '\n';
    }
}
