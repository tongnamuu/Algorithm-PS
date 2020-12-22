#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10][10];
int b[10][10];
int map[10][10][4];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, m;
int ans = 2147483647;
bool range(int x, int y) { return x >= 1 && x <= n&&y >= 1 && y <= m; }
int count() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1 ; j <= m; ++j) {
            if (a[i][j] == 0) ++cnt;
            a[i][j] = b[i][j];
        }
    }
    return cnt;
}
void fill(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while (range(nx, ny) && a[nx][ny] != 6) {
        if (a[nx][ny] == 0) {
            a[nx][ny] = -1;
        }
        nx += dx[dir];
        ny += dy[dir];
    }
}
void solve(int idx, vector<int>& pos) {
    if (idx >= pos.size()) {
        for (int p : pos) {
            int x = p >> 5;
            int y = p & 31;
            for (int dir = 0; dir < 4; ++dir) {
                if (map[x][y][dir]) {
                    fill(x, y, dir);
                }
            }
        }
        int cnt = count();
        ans = min(ans, cnt);
        return;
    }
    int x = pos[idx] >> 5;
    int y = pos[idx] & 31;
    if (a[x][y] == 1) {
        for (int dir = 0; dir < 4; ++dir) {
            map[x][y][dir] = 1;
            solve(idx + 1, pos);
            map[x][y][dir] = 0;
        }
    }
    else if (a[x][y] == 2) {
        for (int dir = 0; dir < 4; dir += 2) {
            map[x][y][dir] = 1;
            map[x][y][dir + 1] = 1;
            solve(idx + 1, pos);
            map[x][y][dir] = 0;
            map[x][y][dir + 1] = 0;
        }
    }
    else if (a[x][y] == 3) {
        for (int dir1 = 0; dir1 < 2; ++dir1) {
            for (int dir2 = 2; dir2 < 4; ++dir2) {
                map[x][y][dir1] = 1;
                map[x][y][dir2] = 1;
                solve(idx + 1, pos);
                map[x][y][dir1] = 0;
                map[x][y][dir2] = 0;
            }
        }
    }
    else if (a[x][y] == 4) {
        for (int except = 0; except < 4; ++except) {
            for (int dir = 0; dir < 4; ++dir) {
                if (dir == except) continue;
                map[x][y][dir] = 1;
            }
            solve(idx + 1, pos);
            for (int dir = 0; dir < 4; ++dir) {
                if (dir == except) continue;
                map[x][y][dir] = 0;
            }
        }
    }
    else if (a[x][y] == 5) {
        for (int dir = 0; dir < 4; ++dir) {
            map[x][y][dir] = 1;
        }
        solve(idx + 1, pos);
        for (int dir = 0; dir < 4; ++dir) {
            map[x][y][dir] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    vector<int>pos;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
            if (a[i][j] >= 1 && a[i][j] <= 5) {
                pos.push_back((i << 5) + j);
            }
        }
    }
    solve(0, pos);
    cout << ans;
}
