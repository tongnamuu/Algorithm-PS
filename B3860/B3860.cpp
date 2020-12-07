#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1000000000000LL
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int a[31][31];
struct Edge { int to, c; };
vector<Edge>adj[901];
long long dist[901];
int next_ghost[901];
int get_node(int x, int y, int m) {
    return x * m + y;
}
bool solve() {
    int n, m; cin >> n >> m;
    if (n == 0 && m == 0) return false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int node = i * m + j;
            dist[node] = INF;
            a[i][j] = 0;
            adj[node].clear();
            next_ghost[node] = 0;
        }
    }
    int g; cin >> g;
    for (int i = 0, x, y; i < g; ++i) {
        cin >> x >> y;
        a[x][y] = 1;
    }
    int e; cin >> e;
    for (int i = 0; i < e; ++i) {
        int x1, y1, x2, y2, t; cin >> x1 >> y1 >> x2 >> y2 >> t;
        a[x1][y1] = 2;
        int start = get_node(x1, y1, m);
        int end = get_node(x2, y2, m);
        adj[start].push_back({ end, t });
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == n - 1 && j == m - 1) break;
            if (a[i][j]) continue;
            int now = get_node(i, j, m);
            for (int dir = 0; dir < 4; ++dir) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny] != 1) {
                    adj[now].push_back({ get_node(nx,ny,m), 1 });
                }
            }
        }
    }
    bool cycle = false;
    dist[0] = 0;
    for (int i = 0; i <= n * m; ++i) {
        for (int now = 0; now < n * m; ++now) {
            for (auto& p : adj[now]) {
                int next = p.to;
                long long nc = dist[now] + p.c;
                if (dist[now] != INF && dist[next] > nc) {
                    if (i == n * m) cycle = true;
                    dist[next] = nc;
                }
            }
        }
    }
    if (cycle) cout << "Never\n";
    else if (dist[n*m - 1] == INF) cout << "Impossible\n";
    else cout << dist[n*m - 1] << '\n';
    return true;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    while (solve());
}
