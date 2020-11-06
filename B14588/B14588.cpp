#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
pair<int, int> a[301];
int adj[301][301];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        for (int j = 1; j <= n; ++j) {
            adj[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (a[i].first < a[j].first) {
                if (a[i].second >= a[j].first) {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
            else if(a[i].first>a[j].first) {
                if (a[j].second >= a[i].first) {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
            else {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        if (adj[u][v] != INF) cout << adj[u][v] << '\n';
        else cout << -1 << '\n';
    }
}
