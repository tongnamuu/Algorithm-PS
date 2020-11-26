#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 4001
int d[N][N];
vector<int>adj[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        d[u][v] = d[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 2147483647;
    for (int i = 1; i <= n; ++i) {
        for(int j=i+1;j<=n;++j){
            if (!d[i][j]) continue;
            for (int k = j+1; k <= n; ++ k) {
                if (d[j][k] && d[k][i]) {
                    ans = min(ans, int(adj[i].size() + adj[j].size() + adj[k].size() - 6));
                }
            }
        }
    }
    if (ans == 2147483647) ans = -1;
    cout << ans;
}
