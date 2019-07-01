#include <iostream>
#include <memory.h>
using namespace std;
int a[9][9];
int n;
int dx[] = { 0,0,-1,1 ,-1,-1,1,1 };
int dy[] = { -1,1,0,0 ,-1,1,-1,1 };
void init() {
	memset(a, 0, sizeof(a));
	a[n / 2][n / 2] = 2;
	a[n / 2 + 1][n / 2] = 1;
	a[n / 2][n / 2 + 1] = 1;
	a[n / 2 + 1][n / 2 + 1] = 2;
}
void go(int x, int y, int col) {
	for (int dir = 0; dir < 8; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		bool change = false;
		while (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == 3 - col) {
			nx += dx[dir];
			ny += dy[dir];
		}
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == col) change = true;
		if (change) {
			while (!(x==nx&&y==ny)) {
				a[nx][ny] = col;
				nx -= dx[dir];
				ny -= dy[dir];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int m; cin >> n >> m;
		init();
		int x, y, col;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> col;
			a[x][y] = col;
			go(x, y, col);
		}
		x = 0, y = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				x += (a[i][j] == 1);
				y += (a[i][j] == 2);
			}
		}
		cout << '#' << test_case << ' ' << x << ' ' << y << '\n';
	}
}