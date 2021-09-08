#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int>adj[52];
int d[52];
int f[52];
int n, m;
void dfs(int now, int p, long double& ans) {
    d[now] = 1;
    for (int next : adj[now]) {
        if (next == p) continue;
        dfs(next, now, ans);
        d[now] += d[next];
        f[now] += f[next];
        ans += pow((double)d[next] / (n - 1), m - f[next]) * pow(double(n - d[next]) / (n - 1), f[next]);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0, u; i < m; ++i) {
        cin >> u;
        f[u]++;
    }
    long double ans = 0;
    dfs(0, -1, ans);
    cout << fixed;
    cout.precision(10);
    cout << ans;
}
