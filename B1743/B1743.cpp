#include <iostream>
using namespace std;
int n, m, k;
int d[101][101];
int check[101][101];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int go(int x, int y) {
	check[x][y] = true;
	int c = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && d[nx][ny] && !check[nx][ny]) {
			c += go(nx, ny);
		}
	}
	return c + 1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0, a, b; i < k; ++i) {
		cin >> a >> b;
		d[a][b] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (d[i][j]==1 && check[i][j] == 0) {
				int cnt=go(i, j);
				if (ans < cnt) ans = cnt;
			}
		}
	}
	cout << ans << '\n';
}