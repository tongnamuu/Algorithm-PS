#include <iostream>
using namespace std;
int n, m;
char a[501][501];
int d[501][501];
int go(int x, int y) {
	if (x >= n || x < 0 || y >= m || y < 0) return 1;
	if (d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	if (a[x][y] == 'U') {
		return d[x][y] = go(x - 1, y);
	}
	else if (a[x][y] == 'R') {
		return d[x][y] = go(x, y + 1);
	}
	else if (a[x][y] == 'D') {
		return d[x][y] = go(x + 1, y);
	}
	else if (a[x][y] == 'L') {
		return d[x][y] = go(x, y - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) d[i][j] = -1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans += go(i, j);
		}
	}
	cout << ans << '\n';
}