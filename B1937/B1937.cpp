#include <iostream>
using namespace std;
int n;
int a[501][501];
int d[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int max(int a, int b) { return a > b ? a : b; }
bool isrange(int x, int y) {
	if (x >= 0 && x < n&&y >= 0 && y < n) return true;
	return false;
}
int go(int x, int y) {
	if (d[x][y] != -1) return d[x][y];
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (isrange(nx, ny)&&a[nx][ny]>a[x][y]) {
			d[x][y] = max(d[x][y], go(nx, ny) + 1);
		}
	}
	if (d[x][y] == -1) return d[x][y] = 1;
	else return d[x][y];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans = max(ans, go(i, j));
		}
	}
	cout << ans << '\n';
}