#include <iostream>
#include <queue>
using namespace std;
char a[51][51];
int d[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int sx = -1, sy = -1, ex = -1, ey = -1;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	queue<pair<int, int>>q;
	queue<pair<int, int>>water;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'D') {
				ex = i, ey = j;
			}
			else if (a[i][j] == 'S') {
				sx = i, sy = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}
	q.push({ sx,sy });
	d[sx][sy] = 1;
	while (!q.empty()||!water.empty()) {
		int k = water.size();
		while (k--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
					if (a[nx][ny] == 'X') continue;
					if (a[nx][ny] == '.') {
						a[nx][ny] = '*';
						water.push({ nx,ny });
					}
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
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
					if ((a[nx][ny] == '.' || a[nx][ny] == 'D') && d[nx][ny] == 0) {
						d[nx][ny] = d[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	if (!d[ex][ey]) cout << "KAKTUS" << '\n';
	else cout << d[ex][ey] - 1 << '\n';
}