#include <iostream>
#include <queue>
using namespace std;
int k, n, m;
int a[201][201];
int d[201][201][31];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int dx1[] = { -2,-2,-1,-1,1,1,2,2 };
int dy1[] = { -1,1,-2,2,2,-2,-1,1 };
struct state {
	int first, second, cnt;
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> k >> m >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	queue<state>q;
	q.push({ 0,0,0 });
	d[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = q.front().cnt;
		if (x == n - 1 && y == m - 1) {
			cout << d[x][y][cnt] - 1 << '\n';
			return 0;
		}
		q.pop();
		if (cnt < k) {
			for (int dir = 0; dir < 8; ++dir) {
				int nx = x + dx1[dir];
				int ny = y + dy1[dir];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny] != 1) {
					if (d[nx][ny][cnt + 1] == 0) {
						d[nx][ny][cnt + 1] = d[x][y][cnt] + 1;
						q.push({ nx,ny,cnt + 1 });
					}
				}
			}
		}
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m && a[nx][ny] != 1) {
				if (d[nx][ny][cnt] == 0) {
					d[nx][ny][cnt] = d[x][y][cnt] + 1;
					q.push({ nx,ny,cnt });
				}
			}
		}
	}
	cout << -1 << '\n'; return 0;
}