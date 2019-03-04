#include <iostream>
#include <queue>
using namespace std;
char a[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
int bfs(int sx, int sy) {
	queue<pair<int, int>>q;
	int d[51][51] = { 0, };
	int cnt = 0;
	d[sx][sy] = 1;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt = d[x][y];
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&d[nx][ny] == 0 && a[nx][ny] == 'L') {
				q.push({ nx,ny });
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'L') {
				int temp = bfs(i, j);
				if (ans < temp) ans = temp;
			}
		}
	}
	cout << ans - 1 << '\n';
}