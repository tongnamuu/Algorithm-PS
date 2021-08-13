#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 10001
vector<int>adj[N];
vector<int>rev[N];
int visit[N];
void dfs1(int now, vector<int>& result) {
    visit[now] = 1;
    for (int next : adj[now]) {
        if (!visit[next]) dfs1(next, result);
    }
    result.push_back(now);
}
void dfs2(int now, vector<int>& result) {
    visit[now] = 2;
    for (int next : rev[now]) {
        if (visit[next] == 1) dfs2(next, result);
    }
    result.push_back(now);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    vector<int>result;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) dfs1(i, result);
    }
    reverse(result.begin(), result.end());
    vector<vector<int>>ans;
    for (int i : result) {
        if (visit[i] == 1) {
            vector<int>scc;
            dfs2(i, scc);
            sort(scc.begin(), scc.end());
            scc.push_back(-1);
            ans.push_back(scc);
        }
    }
    sort(ans.begin(), ans.end(), [](const auto& u, const auto& v) {
        return u[0] < v[0];
    });
    cout << ans.size() << '\n';
    for (auto& v : ans) {
        for (auto& e : v) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}
