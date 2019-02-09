#include <iostream>
#include <queue>
using namespace std;
struct pos {
	int first, second, cnt;
};
char a[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int d[101][101];
queue<pos>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> m >> n;
	int sx = -1, sy = -1;
	int ex = -1, ey = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'C' && sx == -1 && sy == -1) {
				sx = i;
				sy = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'C' && sx != -1 && sy != -1) {
				ex = i;
				ey = j;
				a[i][j] = '.';
			}
		}
	}
	q.push({ sx,sy, 0 });
	d[sx][sy] = 1;
	int ans;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = q.front().cnt;
		if (x == ex && y == ey) {
			ans = cnt - 1;
			break;
		}
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == '*') break;
				if (a[nx][ny] == '.' && d[nx][ny]==0) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny,cnt+1});
				}
				nx += dx[dir];
				ny += dy[dir];
			}
		}
	}
	cout << ans << '\n';
}