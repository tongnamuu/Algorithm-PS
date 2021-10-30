#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>>adj[101];
int indegree[101];
int d[101][101];
int check[101];
void solve(int now) {
    if (check[now])return;
    if (adj[now].size() == 0) {
        d[now][now] = 1;
        return;
    }
    check[now] = 1;
    for (pair<int,int> next : adj[now]) {
        solve(next.first);
        for (int i = 1; i <= 100; ++i) {
            if (d[next.first][i]) {
                d[now][i] += d[next.first][i] * next.second;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, x, y, k; i < m; ++i) {
        cin >> x >> y >> k;
        adj[x].push_back({ y, k });
    }
    solve(n);
    for (int i = 1; i <= 100; ++i) {
        if (d[n][i]) {
            cout << i << ' ' << d[n][i] << '\n';
        }
    }
}
