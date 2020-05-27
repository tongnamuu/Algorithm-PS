#include <iostream>
using namespace std;
char a[101][101];
int d[101][101];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
void go(int x, int y, int n, int m) {
    d[x][y] = 1;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !d[nx][ny] && a[nx][ny] == '#') go(nx, ny, n, m);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j]=='#' && !d[i][j]) {
                go(i, j, n, m);
                ++ans;
            }
        }
    }
    cout << ans;
}