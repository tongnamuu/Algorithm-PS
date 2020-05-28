#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define N 303
#define INF 200000000000000LL
int a[N][N];
long long d[N][N];
const int dx[] = { -1,1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };
struct Edge {
    int x, y;
    long long c;
    bool operator<(const Edge& a) const {
        return c > a.c;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == -2) a[i][j] = 0;
            d[i][j] = INF;
        }
    }
    priority_queue<Edge>q;
    for (int i = 0; i <= m + 1; ++i) {
        d[0][i] = INF;
        if (i < m && a[n][i] >= 0) {
            d[n][i] = a[n][i];
            q.push({ n,i, a[n][i] });
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        d[i][m + 1] = INF;
        if (i > 1 && i < n && a[i][1] >= 0) {
            d[i][1] = a[i][1];
            q.push({ i,1, a[i][1] });
        }
    }
    while (!q.empty()) {
        auto now = q.top(); q.pop();
        if (d[now.x][now.y] < now.c) continue;
        for (int dir = 0; dir < 8; ++dir) {
            int nx = now.x + dx[dir];
            int ny = now.y + dy[dir];
            if (nx >= 0 && nx <= n && ny >= 1 && ny <= m + 1) {
                if (a[nx][ny] == -1) continue;
                long long c = now.c + a[nx][ny];
                if (d[nx][ny] > c) {
                    d[nx][ny] = c;
                    q.push({ nx,ny,c });
                }
            }
        }
    }
    long long ans = INF;
    for (int i = 0; i <= m + 1; ++i) {
        ans = min(ans, d[0][i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, d[i][m + 1]);
    }
    cout << (ans == INF ? -1 : ans);
}