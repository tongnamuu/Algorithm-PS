#include <iostream>
#include <string>
#include <deque>
using namespace std;
char a[103][103];
int d[3][103][103];
int startx[3] = { -1,-1, 0 };
int starty[3] = { -1,-1, 0 };
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, m;
void solve(int idx) {
	deque<pair<int, int>>q;
	q.push_back({ startx[idx], starty[idx] });
	d[idx][startx[idx]][starty[idx]] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1) {
				if (d[idx][nx][ny] == -1 && a[nx][ny] == '.') {
					q.push_front({ nx,ny });
					d[idx][nx][ny] = d[idx][x][y];
				}
				else if (d[idx][nx][ny] == -1 && a[nx][ny] == '#') {
					q.push_back({ nx,ny });
					d[idx][nx][ny] = d[idx][x][y] + 1;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < 2; ++i) startx[i] = starty[i] = -1;
		string s;
		for (int i = 0; i <= m + 1; ++i) {
			a[0][i] = '.';
			a[n + 1][i] = '.';
			d[0][0][i] = d[0][n + 1][i] = -1;
			d[1][0][i] = d[1][n + 1][i] = -1;
			d[2][0][i] = d[2][n + 1][i] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> s;
			a[i][0] = '.';
			a[i][m + 1] = '.';
			d[0][i][0] = d[0][i][m + 1] = -1;
			d[1][i][0] = d[1][i][m + 1] = -1;
			d[2][i][0] = d[2][i][m + 1] = -1;
			for (int j = 1; j <= m; ++j) {
				a[i][j] = s[j - 1];
				if (a[i][j] == '$') {
					if (startx[0] == -1) {
						startx[0] = i;
						starty[0] = j;
					}
					else {
						startx[1] = i;
						starty[1] = j;
					}
					a[i][j] = '.';
				}
				d[0][i][j] = -1;
				d[1][i][j] = -1;
				d[2][i][j] = -1;
			}
		}
		solve(0); solve(1); solve(2);
		int ans = 2147483647;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (d[0][i][j] != -1 && d[1][i][j] != -1 && d[2][i][j]!=-1) {
					int cnt = d[0][i][j] + d[1][i][j] + d[2][i][j];
					if (a[i][j] == '#') cnt -= 2;
					if (cnt < ans) ans = cnt;
				}
			}
		}
		cout << ans << '\n';
	}
}