#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define N 6500
char a[81][81];
struct MaxFlow {
    int n;
    vector<int>adj[N];
    int pred[N];
    int check[N];
    MaxFlow(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            pred[i] = -1;
        }
    }
    void add_edge(int from, int to) {
        adj[from].push_back(to);
    }

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

    int flow() {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            fill(check, check + n, 0);
            ans += dfs(i);
        }
        return ans;
    }
};
int n, m;
int get_node(int x, int y) {
    return m * x + y;
}
bool range(int x, int y) {
    return x >= 0 && x < n&&y >= 0 && y < m;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int total = 0;
    MaxFlow x(n*m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'x') continue;
            total++;
            if (i) {
                if (j) {
                    if (a[i - 1][j - 1] == '.') {
                        if (j & 1) {
                            x.add_edge(get_node(i, j), get_node(i - 1, j - 1));
                        }
                        else {
                            x.add_edge(get_node(i - 1, j - 1), get_node(i, j));
                        }
                    }
                }
                if (j + 1 < m) {
                    if (a[i - 1][j + 1] == '.') {
                        if (j & 1) {
                            x.add_edge(get_node(i, j), get_node(i - 1, j + 1));
                        }
                        else {
                            x.add_edge(get_node(i - 1, j + 1), get_node(i, j));
                        }
                    }
                }
            }

            if (j + 1 < m) {
                if (a[i][j + 1] == '.') {
                    if (j & 1) {
                        x.add_edge(get_node(i, j), get_node(i, j + 1));
                    }
                    else {
                        x.add_edge(get_node(i, j + 1), get_node(i, j));
                    }
                }
            }
        }
    }
    cout << total - x.flow() << '\n';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}