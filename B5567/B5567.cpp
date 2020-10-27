#include <iostream>
#include <queue>
using namespace std;
int a[501][501];
int visit[501];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    queue<pair<int, int>>q;
    q.push({ 1,0 });
    visit[1] = 1;
    int ans = 0;
    while (!q.empty()) {
        int now = q.front().first;
        int dep = q.front().second;
        q.pop();
        for (int next = 2; next <= n; ++next) {
            if (a[now][next] && !visit[next] && dep < 2) {
                visit[next] = 1;
                q.push({ next, dep + 1 });
                ++ans;
            }
        }
    }
    cout << ans;
}
