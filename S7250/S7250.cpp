#include <iostream>
#include <queue>
using namespace std;
char a[1001][1001];
int d[1001][1001][11];
int d2[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m, kkk;
void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d2[i][j] = -1;
			for (int k = 0; k < 11; ++k) {
				d[i][j][k] = -1;
			}
		}
	}
}
struct scot {
	int first, second, small;
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m >> kkk;
		init();
		int ex, ey;
		queue<scot>q;
		queue<pair<int, int>>q2;
		queue<pair<int, int>>fire;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 'S') {
					q.push({ i,j,0 });
					a[i][j] = 'A';
					d[i][j][0] = 0;
				}
				else if (a[i][j] == 'V') {
					q2.push({ i,j });
					a[i][j] = 'A';
					d2[i][j] = 0;
				}
				else if (a[i][j] == 'F') {
					fire.push({ i,j });
				}
				else if (a[i][j] == 'E') {
					ex = i;
					ey = j;
					a[i][j] = 'A';
				}
			}
		}
		while (!q.empty() || !q2.empty()) {
			int k = fire.size();
			while (k--) {
				int x = fire.front().first;
				int y = fire.front().second;
				fire.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
						if (a[nx][ny] == 'A') {
							if (nx == ex && ny == ey) continue;
							fire.push({ nx,ny });
							a[nx][ny] = 'F';
						}
					}
				}
			}
			k = q2.size();
			while (k--) {
				int x = q2.front().first;
				int y = q2.front().second;
				q2.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
						if ((a[nx][ny] == 'F' || a[nx][ny] == 'A') && d2[nx][ny] == -1) {
							d2[nx][ny] = d2[x][y] + 1;
							q2.push({ nx,ny });
						}
					}
				}
			}
			k = q.size();
			while (k--) {
				int x = q.front().first;
				int y = q.front().second;
				int sm = q.front().small;
				q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
						if (a[nx][ny] == 'A'&&d[nx][ny][0] == -1) {
							q.push({ nx,ny,0 });
							d[nx][ny][0] = d[x][y][sm] + 1;
						}
						else if (a[nx][ny] == 'W' && sm < kkk&&d[nx][ny][sm + 1] == -1) {
							q.push({ nx,ny,sm + 1 });
							d[nx][ny][sm + 1] = d[x][y][sm] + 1;
						}
					}
				}
			}
		}
		int ans = d2[ex][ey];
		if (ans == -1) ans = d2[ex][ey] = 2147483647;
		for (int i = 0; i <= kkk; ++i) {
			if (d[ex][ey][i] != -1) {
				if (ans > d[ex][ey][i]) {
					ans = d[ex][ey][i];
				}
			}
		}
		if (ans == d2[ex][ey]) ans = -1;
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}