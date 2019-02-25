#include <iostream>
#include <queue>
using namespace std;
int from[501 * 501];
int a[501][501];
int ans[501][501];
int dx[] = { -1,1,0,1,-1,-1,1,0 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int n, m;
int go(int sx, int sy) {
	if (from[sx * 501 + sy]!= -1) return from[sx * 501 + sy];
	int min = a[sx][sy];
	int minx = -1, miny = -1;
	for (int dir = 0; dir < 8; ++dir) {
		int nx = sx + dx[dir];
		int ny = sy + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
			if (a[nx][ny] < min) {
				min = a[nx][ny];
				minx = nx;
				miny = ny;
			}
		}
	}
	if (minx == -1 && miny == -1) return from[sx * 501 + sy] = sx * 501 + sy;
	else return from[sx * 501 + sy] = go(minx, miny);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	memset(from, -1, sizeof(from));
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) go(i, j);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int temp = from[i * 501 + j];
			ans[temp / 501][temp % 501]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}