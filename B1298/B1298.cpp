#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 101
vector<int>adj[N];
bool check[N];
int pred[N];
int dfs(int now) {
    if (now == -1) return 1;
    for (int next : adj[now]) {
        if (check[next]) continue;
        check[next] = true;
        if (dfs(pred[next])) {
            pred[next] = now;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    fill(pred, pred + N, -1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        fill(check, check + N, false);
        ans += dfs(i);
    }
    cout << ans;
}