#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 102
vector<int>adj[N];
int pred[N];
int check[N];
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
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < N; ++i) {
            adj[i].clear();
            pred[i] = -1;
        }
        int max_t = 0;
        for (int i = 0; i < m; ++i) {
            int t1, t2; cin >> t1 >> t2;
            int x; cin >> x;
            max_t = max(max_t, t2);
            while (x--) {
                int q; cin >> q;
                for (int j = t1; j < t2; ++j) {
                    adj[j].push_back(q);
                }
            }
        }
        int ans = -1;
        int flow = 0;
        for (int i = 0; i <= max_t; ++i) {
            fill(check, check + N, 0);
            flow += dfs(i);
            if (flow == n) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}