#include <iostream>
#include <queue>
using namespace std;
char a[1002][1002];
int d[1002][1002];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int main() {
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> m >> n;
		queue<pair<int, int>>q;
		queue<pair<int, int>>fire;
		for (int i = 0; i <= m + 1; ++i) {
			a[0][i] = '!';
			a[n + 1][i] = '!';
			d[0][i] = 0;
			d[n + 1][i] = 0;
		}
		for (int i = 0; i <= n + 1; ++i) {
			a[i][0] = '!';
			a[i][m + 1] = '!';
			d[i][0] = 0;
			d[i][m + 1] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			getchar();
			for (int j = 1; j <= m; ++j) {
				a[i][j] = getchar();
				if (a[i][j] == '@') {
					q.push({ i,j });
					a[i][j] = '.';
				}
				else if (a[i][j] == '*') fire.push({ i,j });
				d[i][j] = 0;
			}
		}
		bool go = true;
		int ans = -1;
		while (go && (!q.empty() || !fire.empty())) {
			int k = fire.size();
			while (k--) {
				int x = fire.front().first;
				int y = fire.front().second;
				fire.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
						if (a[nx][ny] == '.') {
							a[nx][ny] = '*';
							fire.push({ nx,ny });
						}
					}
				}
			}
			k = q.size();
			while (go && k--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && a[nx][ny] != '#'&&a[nx][ny] != '*'&&d[nx][ny] == 0) {
						d[nx][ny] = d[x][y] + 1;
						if (a[nx][ny] == '!') {
							go = false;
							ans = d[nx][ny];
							break;
						}
						q.push({ nx,ny });
					}
				}
			}
		}
		if (ans == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << ans << '\n';
	}
}