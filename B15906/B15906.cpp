#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define N 501
#define INF 1000000000
char a[N][N];
long long d[N][N][2];
struct Edge {
    int x, y, s;
    long long c;
    bool operator<(const Edge& a) const {
        return c > a.c;
    }
};
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
vector<pair<int, int>>adj[N][N];
void set_warp(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int nx = i, ny = j;
                bool find = false;
                while (!find) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
                        if (a[nx][ny] == '#') {
                            adj[i][j].push_back({ nx,ny });
                            find = true;
                        }
                    }
                    else break;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, t, r, c; cin >> n >>t >> r >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < n; ++j) {
            d[i][j][0] = d[i][j][1] = INF;
        }
    }
    set_warp(n);
    priority_queue<Edge>q;
    d[0][0][0] = 0;
    q.push({ 0,0,0,0 });
    while (!q.empty()) {
        auto now = q.top(); q.pop();
        if (d[now.x][now.y][now.s] < now.c) continue;
        int x = now.x, y = now.y;
        if (!now.s) {
            if (d[x][y][1] > now.c + t) {
                d[x][y][1] = now.c + t;
                q.push({ x, y, 1, now.c + t });
            }
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (d[nx][ny][0] > now.c + 1) {
                        d[nx][ny][0] = now.c + 1;
                        q.push({ nx,ny, 0,now.c + 1 });
                    }
                }
            }
        }
        else {
            for (auto& next : adj[x][y]) {
                if (d[next.first][next.second][1] > now.c + 1) {
                    d[next.first][next.second][1] = now.c + 1;
                    q.push({ next.first,next.second, 1, now.c + 1 });
                }
            }
            if (d[now.x][now.y][0] > now.c) {
                d[now.x][now.y][0] = now.c;
                q.push({ now.x,now.y, 0, now.c });
            }
        }
    }
    cout << min(d[r-1][c-1][0], d[r-1][c-1][1]);
}