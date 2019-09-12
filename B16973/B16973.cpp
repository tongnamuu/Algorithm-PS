#include <iostream>
#include <queue>
using namespace std;
int a[1001][1001];
int sum[1001][1001];
int d[1001][1001];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
bool checksum(int nx, int ny, int h, int w) {
	int s = nx - h + 1;
	int p = ny - w + 1;
	if (sum[nx][ny] - sum[s - 1][ny] - sum[nx][p - 1] + sum[s - 1][p - 1] == 0) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	int h, w, sx, sy, ex, ey;
	cin >> h >> w >> sx >> sy >> ex >> ey;
	sx += (h - 1);
	sy += (w - 1);
	ex += (h - 1);
	ey += (w - 1);
	queue < pair<int, int>>q;
	q.push({ sx,sy });
	d[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx - h + 1 >= 1 && nx <= n&&ny - w + 1 >= 1 && ny <= m) {
				if (!checksum(nx, ny, h, w)) continue;
				if (d[nx][ny] == 0) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << d[ex][ey] - 1 << '\n';
}