#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
struct Pos {
    int x, y;
};
char a[1001][1001];
int d[1001][1001];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
inline bool range(int n, int m, int x, int y) { return x >= 0 && x < n&&y >= 0 && y < m; }
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    sx -= 1, sy -= 1, ex -= 1, ey -= 1;
    queue<Pos>q;
    q.push({ sx,sy });
    d[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        if (x == ex && y == ey) break;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!range(n, m, nx, ny) || a[nx][ny] == '#') continue;
            int cnt = k;
            while (range(n, m, nx, ny) && a[nx][ny] == '.' && cnt > 0) {
                if (!d[nx][ny]) {
                    q.push({ nx,ny });
                    d[nx][ny] = d[x][y] + 1;
                }
                else if (d[n][ny] != -1 && d[nx][ny] <= d[x][y]) break;
                nx += dx[dir];
                ny += dy[dir];
                cnt--;
            }
        }
    }
    cout << d[ex][ey] - 1 << '\n';
}
