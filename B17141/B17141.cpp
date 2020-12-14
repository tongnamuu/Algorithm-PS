#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[51][51];
int d[51][51];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int pos[11];
int pn;
int n, m;
int ans = 2147483647;
bool range(int x, int y) { return x >= 0 && x < n&&y >= 0 && y < n; }
int bfs() {
    queue<int>q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 3) {
                q.push((i << 6) + j);
                d[i][j] = 0;
            }
            else {
                d[i][j] = -1;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front() >> 6;
        int y = q.front() & 63;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!range(nx, ny)) continue;
            if (d[nx][ny] == -1 && a[nx][ny] != 1) {
                q.push((nx << 6) + ny);
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) continue;
            if (d[i][j] == -1) return 2147483647;
            res = max(res, d[i][j]);
        }
    }
    return res;
}
void make_map(int idx, int cnt) {
    if (cnt == m) {
        ans = min(ans, bfs());
        return;
    }
    if (idx >= pn) return;
    for (int i = idx; i < pn; ++i) {
        int x = pos[i] >> 6;
        int y = pos[i] & 63;
        a[x][y] = 3;
        make_map(i + 1, cnt + 1);
        a[x][y] = 2;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                pos[pn++] = (i << 6) + j;
            }
        }
    }
    for (int i = 0; i < pn; ++i) {
        int x = pos[i] >> 6;
        int y = pos[i] & 63;
        a[x][y] = 3;
        make_map(i + 1, 1);
        a[x][y] = 2;
    }
    if (ans == 2147483647) ans = -1;
    cout << ans;
}
