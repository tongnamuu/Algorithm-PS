#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int a[7][6];
int d[7][6][4];
int dy[] = { -1, 0, 1 };
int n, m;
int go(int x, int y, int dir) {
    if (x == n) {
        return d[x][y][dir] = a[x][y];
    }
    int& ret = d[x][y][dir];
    if (ret != INF) return ret;
    for (int d = 0; d < 3; ++d) {
        if (d == dir) continue;
        int nx = x + 1;
        int ny = y + dy[dir];
        if (ny >= 0 && ny < m) {
            ret = min(ret, go(nx, ny, d));
        }
    }
    ret += a[x][y];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            for (int k = 0; k < 3; ++k) {
                d[i][j][k] = INF;
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < 3; ++k) {
            ans = min(ans, go(1, i, k));
        }
    }
    cout << ans;
}