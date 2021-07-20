#include <iostream>
#include <queue>
using namespace std;
int a[1001][1001];
int d[1001][1001];
char x[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, ans = 0; cin >> n >> m;
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            a[i][j] = x[j] - '0';
            if (a[i][j]) ++cnt;
            d[i][j] = -1;
        }
        d[i][m] = -1;
        if (cnt & 1) r++;
    }
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][i]) ++cnt;
        }
        d[n][i] = -1;
        if (cnt & 1) c++;
    }
    d[n][m] = -1;
    queue<pair<int, int>>q;
    q.push({ r,c });
    d[r][c] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nx, ny;
        nx = x - 1;
        ny = m - y;
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && d[nx][ny] == -1) {
            q.push({ nx,ny });
            d[nx][ny] = d[x][y] + 1;
        }
        nx = x + 1;
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && d[nx][ny] == -1) {
            q.push({ nx,ny });
            d[nx][ny] = d[x][y] + 1;
        }
        nx = n - x;
        ny = y - 1;
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && d[nx][ny] == -1) {
            q.push({ nx,ny });
            d[nx][ny] = d[x][y] + 1;
        }
        ny = y + 1;
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && d[nx][ny] == -1) {
            q.push({ nx,ny });
            d[nx][ny] = d[x][y] + 1;
        }
    }
    cout << d[0][0];
}