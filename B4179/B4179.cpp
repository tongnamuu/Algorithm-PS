#include <iostream>
#include <queue>
using namespace std;
char a[1002][1002];
int d[1002][1002];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
queue<pair<int, int>>q; queue<pair<int, int>>fire;
int bfs() {
	while (!q.empty()||!fire.empty()) {
		int k = fire.size();
		while (k--) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
					a[nx][ny] = 'F';
					fire.push({ nx,ny });
				}
			}
		}
		k = q.size();
		while (k--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && a[nx][ny] != '#' && a[nx][ny] != 'F' && d[nx][ny] == 0) {
					d[nx][ny] = d[x][y] + 1;
					if (a[nx][ny] == '!') {
						return d[x][y];
					}
					q.push({ nx,ny });
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= m + 1; ++i) a[0][i] = a[n + 1][i] = '!';
	for (int i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = '!';
	for (int i = 1; i <= n; ++i) {
		cin.get();
		for (int j = 1; j <= m; ++j) {
			a[i][j] = cin.get();
			if (a[i][j] == 'J') {
				q.push({ i,j });
				d[i][j] = 1;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'F') fire.push({ i,j });	
		}
	}
	int ans = bfs();
	if (ans == -1) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';
}